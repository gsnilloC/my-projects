var express = require('express');
var router = express.Router();
var db = require('../conf/database');
var bcrypt = require('bcrypt');
var {isLoggedIn, isMyProfile} = require('../middleware/auth');
const { usernameCheck, passwordCheck, emailCheck, tosCheck, ageCheck,isUsernameUnique, isEmailUnique } = require('../middleware/validation');
const { getPostForUserById } = require('../middleware/posts');

 router.post(
   '/register', 
   usernameCheck, 
   passwordCheck, 
   emailCheck, 
   isUsernameUnique, 
   isEmailUnique, async function(req, res, next) { 
   var {username, email, password} = req.body;

   try {
      var hashedPassword = await bcrypt.hash(password, 3);

      var [resultObject, fields] = await db.execute('INSERT INTO users (username, email,password) VALUES (?,?,?)', [username, email, hashedPassword]);
      
      if (resultObject && resultObject.affectedRows == 1) {
         res.redirect('/login');
      } else {
         return res.redirect('/register');
      }
   } catch (error) {
      next(error);
   }  
 });

 router.post('/login', async function(req, res, next) {
   const {username, password} = req.body;
   if (!username || !password) {
      return res.redirect('/login');
   } else {
      var [rows, fields] = await db.execute ('select id,username, password, email from users where username=?;', [username]);
      var user = rows[0];
      
      if (!user) {
         req.flash('error', 'Invalid username or password');
         req.session.save(function(error){
            return res.redirect('/login');
         })
      } else {
         var passwordsMatch = await bcrypt.compare(password, user.password);
         if ( passwordsMatch){
            req.session.user ={
               userId: user.id,
               email: user.email,
               username: user.username
            };
            req.flash('success', 'You are now logged in');
            req.session.save(function(error){
               return res.redirect('/');
            })
         } else {
            return res.redirect('/login');
         }
      }
   }
 });

 router.get('/profile/:id', getPostForUserById, async function(req, res, next) {
   res.render('profile', { user, posts, isNotProfilePage: false});
 });
 

 router.post('/logout', isLoggedIn, function(req, res,next){
   req.session.destroy(function(error){
      if (error) {
         next(error);
      } else {
         return res.redirect('/');
      }
   })
 });

module.exports = router; 
