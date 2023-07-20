## Functionality
Welcome to our platform, where users can create accounts and seamlessly share their videos with the world. Once registered, users can easily post videos from their accounts. Additionally, our platform fosters a sense of community, as users can engage with each other by leaving comments on posts.

To ensure the utmost security and privacy, all user passwords are encrypted, guaranteeing a safe online experience. When users log in, we create secure sessions to maintain their access securely throughout their visit.

We understand the value of efficient navigation, which is why we have integrated a powerful search feature. Users can quickly find the content they love, enhancing their overall browsing experience.

Every account is treated as a unique entity, with its own dedicated profile page showcasing all the captivating videos posted by that user. This personalized touch allows users to curate their own online presence and share their creativity with the world.

Behind the scenes, I have leveraged the Handlebars framework, a powerful tool that enhances the maintainability and readability of our source code. This ensures a smooth development process allows for continuous improvement and expansion of the platform's capabilities.

https://github.com/gsnilloC/my-projects/assets/83888230/7883badb-8092-4eb9-b51d-e4db1e82aded

## Build Instructions
1. Within the applications folder run the command ```npm run builddb``` to build the tables in your database and view them in your preferred workbench.

2. For database credentials, create a ```.env``` file within the application holder that will hold the credentials needed to access your database.
```
DB_HOST="localhost"
DB_NAME="roadStreamDB"
DB_USER="root"
DB_PASSWORD="password"
PORT="3000" 
```
3. In your terminal run the command ```npm install``` within the applications folder in order to install all needed dependencies. 

## Run Instructions
1. In your terminal run the command ```npm start``` within the applications folder in order to start local server.
2. Then in your favorite browser type ```localhost``` in the URL.
