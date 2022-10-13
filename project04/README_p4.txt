Scottie Yang Miaoyi
CS333 - Project 4
Mar 11, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project04/
|__/C/
|  |__/qSort.c
|  |__/factorial.c
|__/JavaScript/
|  |__/task01.js
|  |__/task02.js
|  |__/task03.js

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<<< Task De-Brief >>>
<< Part I >>
NOTE: For all operations please locate into ./project04/ using the "cd" command.
ROOT: C/
|__/qSort.c
|__/factorial.c
< Task 01>
GOAL: Given an array of random integers, sort the array in a way that the even numbers appear first and the odd numbers appear later.
TO COMPILE $ gcc -o qSort qSort.c
TO RUN $ ./qSort
OUTPUT << miaoyi@Hermes C % ./qSort   
The sorted array is: 12 10 8 6 4 2 0 1 3 5 7 9 11 13 

< Task 02> (EXTENSION)
GOAL: Write a function that takes in an integer argument and returns its factorial value as an integer, both recursively and (EXTENSION) iteratively.
TO COMPILE $ gcc -o factorial factorial.c
TO RUN $ ./factorial (int), note that you MUST put ONE (int) after "./factorial" to serve as a command-line argument. See example below:
CORRECT Example 1: $ ./factorial 12
FALSE Example 1: $ ./factorial PutaGuapa
FALSE Example 2: $ ./factorial
OUTPUT (with CORRECT Example 1) << miaoyi@Hermes C % ./factorial 12
The factorial is 479001600, to compute it RECURSIVELY takes 0.000003 seconds. 
The factorial is 479001600, to compute it ITERATIVELY takes 0.000001 seconds. 
OUTPUT << miaoyi@Hermes C % ./factorial 13
The factorial is 1932053504, to compute it RECURSIVELY takes 0.000004 seconds. 
The factorial is 1932053504, to compute it ITERATIVELY takes 0.000002 seconds.
OUTPUT << miaoyi@Hermes C % ./factorial 14
The factorial is 1278945280, to compute it RECURSIVELY takes 0.000003 seconds. 
The factorial is 1278945280, to compute it ITERATIVELY takes 0.000001 seconds. 
OUTPUT << miaoyi@Hermes C % ./factorial 15
The factorial is 2004310016, to compute it RECURSIVELY takes 0.000004 seconds. 
The factorial is 2004310016, to compute it ITERATIVELY takes 0.000001 seconds. 
ANSWER: It turns out that, function could be treat as a type and could be manipulated by address; the program breaks down eventually when computing 14! and 15!, since it is evident that the answers are no longer correct. This probably has to do with how large these quantities are and how much space is allocated for them in memory.

<< Part II >>
NOTE: For this part regarding the details below-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/ixNHIQ
NOTE: For all operations please install node.js ($ brew install node), and locate into ./project03/JavaScript using the "cd" command.
ROOT: JavaScript/
|__/task01.js
|__/task02.js
|__/task03.js
< Task 01>
GOAL: This program uses all these control flow statements.
TO TEST $ node task01.js
OUTPUT << % node task01.js
0
1
2
0
1
2
3
0
1
2
3
4
a is less than 6.
Yes, I am crazyyyyiaa!
Yes

< Task 02>
GOAL: This program shows how are functions treated in the language as a data type.
TO TEST $ node task02.js
OUTPUT << % node task02.js 
Displayed from original
Displayed from alias

< Task 03>
GOAL: This program shows how are functions treated in the language as a data type.
TO TEST $ node task03.js
OUTPUT << % node task03.js 
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/gBpHIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ