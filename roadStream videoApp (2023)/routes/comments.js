var express = require('express');
const { isLoggedIn } = require('../middleware/auth');
var router = express.Router();
var db = require("../conf/database");

router.post('/create', isLoggedIn, async function (req, res, next) {
  var { userId, username } = req.session.user;
  var { postId, comment } = req.body;

  try {
    var [insertResult, _] = await db.execute(
      `INSERT INTO comments (text, fk_postId, fk_authorId) 
            VALUES (?, ?, ?)`,
      [comment, postId, userId]
    );

    if (insertResult && insertResult.affectedRows === 1) {
      req.flash('success', 'Comment added successfully');
      return res.status(201).json({
        commentId: insertResult.insertId,
        username: username,
        commentText: comment,
        userId: userId
      });
    } else {
      req.flash('error', 'Could not post comment');
    }
  } catch (error) {
    next(error);
  }

  // Redirect the user back to the same page
  res.redirect('back');
});

module.exports = router;
