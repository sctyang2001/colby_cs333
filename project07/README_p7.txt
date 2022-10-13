Scottie Yang Miaoyi
CS333 - Project 7
Apr 29, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project07/
|__/C/
|  |__/numberoftimes.c
|  |__/timepercall.c
|  |__/not_output.csv
|  |__/tpc_output.csv
|__/JavaScript/
|  |__/task02.js

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<< Part I >>
NOTE: For all operations please locate into ./project07/C/ using the "cd" command;
< Task 01>
ROOT: project07/
|__/C/
|  |__/timepercall.c
|  |__/tpc_output.csv
GOAL: The program explores the time that it takes (on average) to allocate a certain amount of memory.
TO COMPILE $ gcc -o test timepercall.c
TO RUN (with command line argument) $ ./test
OUTPUT << miaoyi@Hermes
(A well-oriented table, please check "tpc_output.csv" under the same folder for output I saved.)
ANSWER to question:
(EXTENSION: additional graphs.)(Under the same folder generated "tpc_1.png" graph using output.) Using the graph, we see the relationship between the time of a "malloc()" call takes and the number of bytes for that call is in a positive linear relationship. I estimate "malloc()" is around O(n) or O(log n) based on the shape.

< Task 02>
ROOT: project07/
|__/C/
|  |__/numberoftimes.c (EXTENSION: command-line argument enabled.)
|  |__/not_output.csv
NOTE: This program contains a command-line argument input to run.
GOAL: The program explores the time that it takes (on average) to allocate a certain amount of memory over time to see if the time of a memory management call changes with the number of allocation and free operations the program has executed.
TO COMPILE $ gcc -o test numberoftimes.c
TO RUN (with command line argument) $ ./test (integer: input size)
a. interrupt.c: A C program that can be interrupted with `CTRL+C` on the keyboard. 
OUTPUT << miaoyi@Hermes
(A well-oriented table, please check "not_output.csv" under the same folder for output I saved.)
ANSWER to question:
(EXTENSION: additional graphs.)(Under the same folder generated "not_10000.png" and "not_10000000.png" graph using output, showing time for 10000 and 10000000 calls to "malloc()" and "free()" to complete in seconds versus the number of previous calls that the program has made.) Using the graph, we could see the more calls the program has already made, the less costly a new call is. In addition, this relationship seems effected by the input size, and it looks like an inverse logarithmic correlation.

<< Part II >>
NOTE: For this part regarding the details shown below, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/iIahIQ
NOTE: For all operations please install node.js ($ brew install node), and locate into ./project07/JavaScript using the "cd" command.
ROOT: project07/
|__/JavaScript/
|  |__/task02.js
GOAL: The program demonstrates an experiment with automatic memory management.
TO TEST $ node task02.js
OUTPUT << % node task02.js
The execution time is 4ms.
The execution time is 7ms.
The execution time is 6ms.
The execution time is 6ms.
The execution time is 7ms.
The execution time is 6ms.
The execution time is 8ms.
The execution time is 5ms.
The execution time is 6ms.
The execution time is 6ms.
The execution time is 7ms.
The execution time is 5ms.
The execution time is 8ms.
The execution time is 5ms.
The execution time is 7ms.
The execution time is 6ms.
The execution time is 6ms.
The execution time is 6ms.
The execution time is 7ms.
The execution time is 5ms.
The execution time is 8ms.
The execution time is 4ms.
The execution time is 7ms.
The execution time is 5ms.
The execution time is 6ms.

NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/iIahIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ