var validator = require ('validator');
var db = require('../conf/database');

module.exports = {
    usernameCheck: function (req, res, next) {
        var {username}  = req.body;
        username = username.trim();
        if (!validator.isLength(username, {min: 3})) {
            req.flash('error','username must be at least 3 characters');
         } 

         if (!/[a-zA-Z]/.test(username.charAt(0))) {
            req.flash('error','username must be begin with a character');
         }
         
         if (req.session.flash.error){
            res.redirect('/register');
         } else {
            next();
         }
    },
    passwordCheck: function (req, res, next) {
        var {password} = req.body;
        if (!validator.isLength(password, {min:8})){
            req.flash('error','password must be at least 8 characters');
        }

        if(!/^(?=.*[A-Z])(?=.*\d)(?=.*[\/\*\-\+!@#\$%\^&~\[\]]).+$/.test(password)){
            req.flash('error','password must contain at least one of the follwing special characters: / * - + ! @ # $ ^ & ~ [ ]');
        }

        if (req.session.flash.error){
            res.redirect('/register');
         } else {
            next();
         } 
    },
    emailCheck: function (req, res, next) {
        var {email} = req.body;
        if (!validator.isEmail(email)){
            req.flash('error', 'email is not valid')
        }
        next();
    },
    tosCheck: function (req, res, next) {},
    ageCheck: function (req, res,next) {},
    isUsernameUnique: async function (req, res, next) {
        var {username} = req.body;
        try {
            var [rows, fields] = await db.execute('select id from users where username=?;', [username]);
            if (rows && rows.length > 0) {
               req.flash('error', `${username} is already registered`)
               return req.session.save(function(error) {
                  res.redirect('/register');
               });
            } else {
                next();
            }
        } catch {
            next(error);
        }
    },
    isEmailUnique: async function (req, res, next) {
        var {email} = req.body;
        try {
            var [rows, fields] = await db.execute('select id from users where username=?;', [email]);
            if (rows && rows.length > 0) {
               req.flash('error', `${email} is already registered`)
               return req.session.save(function(error) {
                  res.redirect('/register');
               });
            } else {
                next();
            }
        } catch {
            next(error);
        }
    },
}