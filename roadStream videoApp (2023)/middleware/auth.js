module.exports =  {
    isLoggedIn: function (req, res, next) {
        if (req.session.user){
            next();
        } else {
            req.flash('error', 'You must be logged in');
            req.session.save(function (error) {
                if (error) next (error);
                    res.redirect('/login');
            })
        }
    },
    isMyProfile: function (req, res, next) {
        var {id} = req.params;
        if (id == req.session.user.userId){
            next();
        } else {
            req.flash('error', 'This is not your profile');
            req.session.save(function (error) {
                if (error) next (error);
                    res.redirect('/');
            })
        }
    }
}