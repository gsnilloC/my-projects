var pathToFFMPEG = require("ffmpeg-static");
var exec = require("child_process").exec;
var db = require("../conf/database");

module.exports = {
  makeThumbnail: function (req, res, next) {
    if (!req.file) {
      next(new Error("File upload failed"));
    } else {
      try {
        var destinationOfThumbnail = `public/images/uploads/thumbnail-${
          req.file.filename.split(".")[0]
        }.png`;
        var thumbnailCommand = `${pathToFFMPEG} -ss 00:00:01 -i ${req.file.path} -y -s 200x200 -vframes 1 -f image2 ${destinationOfThumbnail}`;
        exec(thumbnailCommand);
        req.file.thumbnail = destinationOfThumbnail;
        next();
      } catch (error) {
        next(error);
      }
    }
  },
  getPostForUserById: async function (req, res, next) {
    try {
      const userId = req.params.id;
      const [userRows, _] = await db.execute(
        "SELECT * FROM users WHERE id = ?",
        [userId]
      );
      const user = userRows[0];

      if (!user) {
        req.flash("error", "Profile not found");
        return res.redirect("/");
      }

      const [postRows, __] = await db.execute(
        "SELECT * FROM posts WHERE fk_userId = ?",
        [userId]
      );
      const posts = postRows;

      res.render("profile", { user, posts });
    } catch (error) {
      next(error);
    }
  },
  getPostById: async function (req, res, next) {
    var id = req.params.id;
    try {
      let [rows, _] = await db.execute(
        `SELECT u.username, u.id, p.video, p.title, p.description, p.id, p.createdAt
            FROM posts p 
            JOIN users u
            ON p.fk_userId = u.id
            WHERE p.id=?`,
        [id]
      );

      const post = rows[0];
      if (!post) {
        req.flash("error", "Could not find post");
        return res.redirect("/");
      }
      res.locals.post = post;
      next();
    } catch (error) {
      next(error);
    }
  },
  getCommentsForPostById: async function (req, res, next) {
    const { id } = req.params;

    try {
      const [rows, _] = await db.execute(
        `
      SELECT u.username, c.text, c.createdAt
      FROM comments c
      JOIN users u ON c.fk_authorId = u.id
      WHERE c.fk_postId = ?;
    `,
        [id]
      );

      if (!res.locals.post) {
        res.locals.post = {};
      }

      res.locals.post.comments = rows;
      next();
    } catch (error) {
      next(error);
    }
  },
  getRecentPosts: async function (req, res, next) {
    try {
      const [rows, _] = await db.execute(`
      SELECT u.username, p.video, p.title, p.description, p.id, p.createdAt
      FROM posts p
      JOIN users u ON p.fk_userId = u.id
      ORDER BY p.createdAt DESC
      LIMIT 12;
    `);

      res.locals.recentPosts = rows;
      next();
    } catch (error) {
      next(error);
    }
  },
};
