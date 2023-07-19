var express = require("express");
var { isLoggedIn, isMyProfile } = require('../middleware/auth');
var router = express.Router();

const { getRecentPosts } = require('../middleware/posts');

router.get('/',  function (req, res, next) {
  res.render('index', {  title: "Home",isIndexPage: true, isNotProfilePage: true});
});

router.get("/login", function (req, res) {
  res.render("login", { title: "Login", isIndexPage: false, isNotProfilePage: true });
});

router.get("/postvideo", isLoggedIn, function (req, res) {
  res.render("postvideo", { title: "Post", isIndexPage: false, isNotProfilePage: true });
});

router.get("/register", function (req, res) {
  res.render("register", { title: "Register", isIndexPage: false , isNotProfilePage: true});
});

module.exports = router;
