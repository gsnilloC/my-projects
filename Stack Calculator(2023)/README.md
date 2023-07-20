[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10058193&assignment_repo_type=AssignmentRepo)
# Assignment 1 Documentation

Collins Gichohi

CSC 413-05

## Scope of Work
_______________________________________________________________________________________________
| Requirement               | Completed? | Comments from student                               |
| ------------------------- | ---------- | ---------------------                               |
| 1 - Implement algorithm   |  Yes       | Algorithm implemented properly using stack.                                                     |
| 2 - Tests                 |  Yes       | Passed, all the tests in test package. Attempted to test in terminal but not successful |
| 3 - Class implementations |  Yes       | All subclassses for the operator classes have been created within different files.|

## Class Diagrams

![IMG_0991](https://user-images.githubusercontent.com/83888230/219910094-de987d2a-2e55-4465-b911-9a6489db7900.jpg)


## Results and Conclusions

### What I Learned

One thing that this assignment taught me is how to properly plan out my code before sitting in front of the computer. I took the professor's advice and used old fashion pen and paper to write out all my thoughts and questions which allowed to make a plan. I was then able to break up the project into chunks that helped me feel less overwhelmed and made the coding process much smoother.

This assignment also gave me a much better understanding of classes and their hierachies. I was also able to finally get a grasp on the different modifiers and how they can be used to encapsulate information properly. Another thing that this assignment has taught me is how to use the stack data structure to create a calculator. 

Although I am still having difficulty I also learned how to rely more on the command line on my computer to run my progarm, but to also commit and push my work to github. 

### Challenged I Encountered
One major challenge I had during this assignemnt was the debugging stage. My debugger was not working correctly and when I launched it nothing would come up. I looked through many forums and watch many videos but I still could not find a solution.

Another challenge I encountered was when a paranthesis was present in the given expression, my code would throw an EmptyStackException. This is because the code was trying tio peek an empty stack. One way I was able to fix this issue was to use the priority of the paranthesis to be able to check if a token is a paranthesis operator. I also added a check that made sure that if the operator stack was empty the while loop in charge of 
