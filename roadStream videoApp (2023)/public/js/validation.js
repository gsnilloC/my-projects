function validation() {
    let username = document.getElementById("username").value;
    const validUsername = /^[a-zA-Z0-9]+$/;

    let password = document.getElementById("password").value;
    const validPassword = /^(?=.*[A-Z])(?=.*\d)(?=.*[\/\*\-\+!@#\$%\^&~\[\]]).+$/;
    let confirmedPassWord = document.getElementById("confirmedPassword").value;
    
    if (("A" > username[0] || "Z" < username[0]) && ("a" > username[0] || "z" < username[0])){
        document.getElementById("message").innerHTML = "Username must begin with a letter";
        return false;
    }

    if (username.length < 3 || !validUsername.test(username)) {
        document.getElementById("message").innerHTML = "Username must have at least 3 alphanumeric characters";
        return false;
    }

    if(password.length < 8) {
        document.getElementById("message").innerHTML = "Password length must be at least 8 characters";
        return false;
    }

    if (!validPassword.test(password)){
        document.getElementById("message").innerHTML = "Password must contain at least 1 upper case letter, 1 number and 1 of the following characters:  / * - + ! @ # $ ^ & ~ []";
        return false;
    }

    if (confirmedPassWord != password){
        document.getElementById("message").innerHTML = "Passwords do not match";
        return false;
    }

    return true;
}