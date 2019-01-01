# Big-Number-Calculate
This program is written by C, and IDE is CLion.
## Origin
The main function of this program is to calculate big numbers.<br>
As we know, the max number of C is 2<sup>64</sup>-1 (It's about 20 digits), if we want to calculate the number with 30 digits? Don't tell me to use double type, it has errors in C... So I want to make a program that can calculate big numbers, and this program was born.

## Function
As the name suggests, this program provides not only **add**, **subtract** ,and **multiply** function to calculate the numbers with max to 10000 digits but also **factorial** with up to 3248! 
(But according to my computer, it will cost me 64 seconds to calculate)

## How to use
In the first line, enter a number.

### Factorial mode
If the number is ***negative***, it will be factorial mode.
The result will be the factorial of the number without negative sign.<br>
e.g.<br> 
Input: -6<br>
Output: 720

### Calculation mode
If the number is ***positive***, it will be the counts of the following numbers, and then enter numbers to calculate. 
There provides **add**, **subtract**, and **multiply** functions to calculate.

#### Add
Enter the number directly.<br>
**e.g.**<br> 
Input:<br>3<br>5 10 27<br>
Output: 42

#### Subtract
Enter the negative sign " - " before the number without any space.<br>
**e.g.**<br>
Input:<br>2<br>17 -9<br>
Output: 8

Input:<br>2<br>12 -19<br>
Output: -7

#### Multiply
Enter the multiplication sign " * " before the number without any space.<br> 
**e.g.**<br>
Input:<br>4<br>34 *12 *46 *77<br>
Output: 1445136

Input:<br>3<br>34 *-12 *7<br>
Output: -2856


## Path
The path of code is at "Big-Number-Calculate/main.c"