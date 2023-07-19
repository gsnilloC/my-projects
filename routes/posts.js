var express = require("express");
var router = express.Router();
var multer = require("multer");
var db = require("../conf/database");

const { makeThumbnail, getPostById, getCommentsForPostById} = require("../middleware/posts");
const { isLoggedIn } = require("../middleware/auth");

const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    cb(null, "public/videos/uploads");
  },
  filename: function (req, file, cb) {
    var fileExt = file.mimetype.split("/")[1];
    const uniqueSuffix = Date.now() + "-" + Math.round(Math.random() * 1e9);
    cb(null, `${file.fieldname}-${uniqueSuffix}.${fileExt}`);
  },
});

const upload = multer({ storage: storage });

router.post(
  "/create",
  isLoggedIn,
  upload.single("uploadVideo"),
  makeThumbnail,
  async function (req, res, next) {
    var { title, description } = req.body;
    var { path, thumbnail } = req.file;
    var { userId } = req.session.user;

    try {
      var [insertResult, _] = await db.execute(
        `INSERT INTO posts (title, description, video, thumbnail, fk_userId) VALUES (?,?,?,?,?)`,
  [title, description, path, thumbnail, userId]

      );
      if (insertResult && insertResult.affectedRows) {
        req.flash("success", "Your post was created");
        return req.session.save(function (error) {
          if (error) next(error);
          return res.redirect("/");
        });
      } else {
        next(new Error("Post could not be created"));
      }
    } catch (error) {
      next(error);
    }
    res.end();
  }
);

router.get("/viewpost/:id(\\d+)", getPostById, getCommentsForPostById,async function (req, res, next) {
  res.render("viewpost", { title: `${res.locals.post.title}`, post: res.locals.post });
});


router.get('/search', async function (req, res, next) {
  var { searchValue } = req.query;
  try {
    var [rows, _] = await db.execute(
      `SELECT id, title, thumbnail, concat_ws(' ', title, description) AS haystack 
      FROM csc317db.posts
      HAVING haystack LIKE ?`,
      [`%${searchValue}%`]
    );
  } catch (error) {
    next(error);
  }
  if (searchValue && rows.length === 0) {
    req.flash('error', 'No Search Results Found');
  }

  if (!searchValue || rows.length === 0) {
    try {
      var [recentPosts, __] = await db.execute(
        `SELECT id, title, thumbnail 
        FROM csc317db.posts
        ORDER BY createdAt DESC
        LIMIT 12`
      );
      res.locals.posts = recentPosts;
    } catch (error) {
      next(error);
    }
  } else {
    res.locals.posts = rows;
  }

  res.render('index' ,{  title: "Home",isIndexPage: true} );
});


router.get('/delete/:id', async function (req, res, next) {
  const postId = req.params.id;

  try {
    await db.execute('DELETE FROM comments WHERE fk_postId = ?', [postId]);

    const [deleteResult, _] = await db.execute(
      'DELETE FROM posts WHERE id = ?',
      [postId]
    );

    if (deleteResult && deleteResult.affectedRows) {
      req.flash("success", "Post deleted successfully");
    } else {
      req.flash("error", "Failed to delete post");
    }

    return req.session.save(function (error) {
      if (error) next(error);
      return res.redirect("/users/profile/" + req.session.user.userId);
    });
  } catch (error) {
    next(error);
  }
});


module.exports = router;
