**TASK. Favorite colour program**

***1. Read the following user story and requirement.***

***User story***

As a user I want to be able to convert text file with an information related to image 16x16 based on my favorite colour preferences: if we have a pixel of my favorite color then corresponding left neighbor pixel and top neighbor pixel should be changed to that color. This will allow me to have more beatiful pictures.


***Requirement 1:***

User should be able to provide input file name, favorite color info and the name of the output file.

***Requirement 2:***

Program should be able to check each data point of the input 16x16 format and if it matches provided favorite colour then neighbor left and neighbor top data points should be set to that color as well.

***Requirement 3:***

Program should validate the input data format and report 

***Design notes***

We are plan to use input format like this. Each pixel is stored as 3 integers separated by comma, each integer should belong to the range from 0 to 255. Each line contains 16 pixels separated by space. File should contain 16 lines.


***2. Test cases***

Write 5 different test cases to cover different scenarios for the user story and requirements from above. Automate them.

***3. Implementation***

Implement a C++ program based on the requirements from above. Use your automation to test it.

