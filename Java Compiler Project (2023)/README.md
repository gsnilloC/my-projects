[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/VZQ8t-Ug)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10929227&assignment_repo_type=AssignmentRepo)
# Assignment 4 Documentation

Author: Collins Gichohi

## Overview of code skeleton

The folders `.devcontainer`, `.vscode`, and `lib` contain configuration information that must not be deleted or modified. The remaining folders will be discussed in class.

## Scope of Work

| Requirement                                             | Completed? | Comments from student |
| ------------------------------------------------------- | ---------- | --------------------- |
| 1. New constrainer error added (`SelectorTypeMismatch`) | [✔️]         |                       |
| 2. New types constrained                                | [✔️]         |                       |
| 3. New statements constrained                           | [✔️]         |                     |
| 4. All debug statements removed; output correct         | [✔️]         |                       |
| 5. Manually tested from the command line                | []         |testInvalidSelect is failing, however in the debug console the output is correct and a SelectorTypeMismatch is properly thrown. Also not passing the second testValidSelect test, I think it could be an issue with the decoration of expressions with their intrinsic type trees.                     |

## Results and Conclusions

### What I Learned

This project gave me more exposure to the debugger. I now understand how to utilize breakpoints to pinpoint problems within the code instead of aimlessly stepping through each function trying to figure out where the problem is located. Now, I can confidently say that the debugger is something that I am now fully comfortable with. Not only is it extremely valuable when coding but it is also a great tool to learn what is happening when you execute each function and gives a greater understandning of the inner workings of your code. 

### Challenges I Encountered

I understood how to implement knew statements into the constrainer, such as unless and if without else. However, for the select statements the logic was much more complicated. I found myself understanding what I needed to do but, not being able to find a way to do it.

Something I could not figure out was why for invalid test cases, they would all have the gray circle and would not run. However, in the debug console the output is correct. The tests were also not compiling at all in the terminal. 

<img width="143" alt="Screenshot 2023-04-23 at 8 03 44 PM" src="https://user-images.githubusercontent.com/83888230/233891099-d0ae4afe-ddcc-40a1-bc4d-d881ea54b06e.png">
