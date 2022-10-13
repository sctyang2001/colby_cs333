Scottie Yang Miaoyi
CS333 - Project 3
Mar 4, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project03/
|__/C/
|  |__/cstk.c
|  |__/cstk.h
|  |__/cstktest.c
|__/JavaScript/
|  |__/task01.js
|  |__/task02.js
|  |__/task03.js

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<<< Task De-Brief >>>
NOTE: For all operations please locate into ./project02/ using the "cd" command.
<< Part I >>
GOAL: implement a stack by using an array in this part. The program is made able to use the stack to hold a list of integers and print out the list in the original order and the reverse order.
ROOT: C/
|__/cstk.c
|__/cstk.h
|__/cstktest.c
TO COMPILE $ gcc -o cstktest cstktest.c cstk.c
TO TEST $ ./cstktest
OUTPUT << miaoyi@Hermes C % ./cstktest    
The original list: 0 1 2 3 4 5 6 7 8 9 
The reversed list: 9 8 7 6 5 4 3 2 1 0 

<< Part II >>
NOTE: For this part regarding the details below-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/ixNHIQ
NOTE: For all operations please install node.js ($ brew install node), and locate into ./project03/JavaScript using the "cd" command.
ROOT: JavaScript/
|__/task01.js
|__/task02.js
|__/task03.js
< Task 01>
GOAL: This program demonstrates naming conventions and identifier scoping, also serves as the extension of shadowing and hoisting.
TO TEST $ node task01.js
OUTPUT << % node task01.js
Global variable: 5
Loop variable: 0
Without let: 4
I'm local
I'm local
I'm global
I'm local
I'm local
undefined 
< Task 02>
GOAL: This program demonstrates basic operation in js using Binary Search.
TO TEST $ node task02.js
OUTPUT << % node task02.js 
4
< Task 03>
GOAL: This program introduces build-in types and aggregate types.
TO TEST $ node task03.js
OUTPUT << % node task03.js 
My age is: 19
0
2
5
USA
100

NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/ixNHIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ