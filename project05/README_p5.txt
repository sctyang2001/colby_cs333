Scottie Yang Miaoyi
CS333 - Project 5
Mar 20, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project05/
|__/C/
|  |__/clltest.c
|  |__/linkedlist.c
|  |__/linkedlist.h
|__/JavaScript/
|  |__/linkedlist.js

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<<< Task De-Brief >>>
NOTE: For all operations please locate into ./project05/ using the "cd" command.
<< Part I >>
GOAL: Implementation the LinkedList data structure.
ROOT: C/
|__/clltest.c
|__/linkedlist.c
|__/linkedlist.h
TO COMPILE $ gcc -o clltest clltest.c linkedlist.c
TO TEST $ ./clltest
OUTPUT << miaoyi@Hermes C % ./clltest   
After initialization
value: 18
value: 16
value: 14
value: 12
value: 10
value: 8
value: 6
value: 4
value: 2
value: 0

After squaring
value: 324
value: 256
value: 196
value: 144
value: 100
value: 64
value: 36
value: 16
value: 4
value: 0

removed: 16

No instance of 11

After removals
value: 324
value: 256
value: 196
value: 144
value: 100
value: 64
value: 36
value: 4
value: 0

After append
value: 324
value: 256
value: 196
value: 144
value: 100
value: 64
value: 36
value: 4
value: 0
value: 11

After clear

After appending
value: 0
value: 1
value: 2
value: 3
value: 4

popped: 0
popped: 1

After popping
value: 2
value: 3
value: 4

List size: 3

<< Part II >>
NOTE: For this part regarding the details below-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/XBFxIQ
NOTE: For all operations please install node.js ($ brew install node), and locate into ./project03/JavaScript using the "cd" command.
ROOT: JavaScript/
|__/linkedlist.js
GOAL: Implements the Linked List in JS.
TO TEST $ node linkedlist.js
OUTPUT << % node linkedlist.js
Push A
Push B
Push C
Print out linkedlist:
C
B
A
Pop C
Print out linkedlist:
B
A
Append 100
Print out linkedlist:
B
A
100
Remove 100
Print out linkedlist:
B
A
Check size
2
Print out linkedlist:
miaoyi@Hermes JavaScript % node linkedlist.js
Push A
Push B
Push C
Print out linkedlist:
C
B
A


Pop C
Print out linkedlist:
B
A


Append 100
Print out linkedlist:
B
A
100


Remove 100
Print out linkedlist:
B
A
Check size
2
Print out linkedlist:
miaoyi@Hermes JavaScript % node linkedlist.js
Push A
Push B
Push C
Print out linkedlist:
C
B
A
 
Pop C
Print out linkedlist:
B
A
 
Append 100
Print out linkedlist:
B
A
100
 
Remove 100
Print out linkedlist:
B
A
 
Check size
2
 
Check free
 
Print out linkedlist:
miaoyi@Hermes JavaScript % node linkedlist.js
Push A
Push B
Push C
Print out linkedlist:
C
B
A
 
Pop C
Print out linkedlist:
B
A
 
Append 100
Print out linkedlist:
B
A
100
 
Remove 100
Print out linkedlist:
B
A
 
Check size
2
 
Check free
Print out linkedlist:


NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/XBFxIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ