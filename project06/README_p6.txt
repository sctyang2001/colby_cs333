Scottie Yang Miaoyi
CS333 - Project 6
Mar 20, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
project06/
|__/C/
|  |__/wordcounter
|  |  |__/wordcounter.c
|  |  |__/wordcounter.h
|  |  |__/WCtest.c
|  |  |__/wctest.txt
|  |__/signalhandler
|  |  |__/interrupt.c
|  |  |__/floatingpointexception.c
|  |  |__/segfault.c
|__/JavaScript/
|  |__/wordcounter.js

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<< Part I >>
< Task 01>
ROOT: project06/
|__/C/
|  |__/wordcounter
|  |  |__/wordcounter.c
|  |  |__/wordcounter.h
|  |  |__/WCtest.c
|  |  |__/wctest.txt
NOTE: For all operations please locate into ./project06/wordcounter using the "cd" command; this program contains a command-line argument input to run.
GOAL: This program implements a word counter that is able to count the number of occurrences of every word in a text file.
TO COMPILE $ gcc -o wctest WCtest.c wordcounter.c
TO RUN (with command line argument) $ ./wctest wctest.txt
OUTPUT << miaoyi@Hermes
This is after wc_read happens...
the             17
of              7
and             6
was             5
with            4
in              4
a               3
windows         3
wings           2
portion         2
central         2
were            2
broken          2
but             2
up              2
had             2
been            2
claws           1
crab            1
thrown          1

< Task 02>
ROOT: project06/
|__/C/
|  |__/signalhandler
|  |  |__/interrupt.c
|  |  |__/floatingpointexception.c
|  |  |__/segfault.c
NOTE: For all operations please locate into ./project06/signalhandler using the "cd" command.
GOAL: This compilation of programs creates examples of signal handling in C.
TO COMPILE $ gcc -o shtest (file)
TO RUN (with command line argument) $ ./shtest
a. interrupt.c: A C program that can be interrupted with `CTRL+C` on the keyboard. 
OUTPUT << miaoyi@Hermes
(ONCE user press CTRL+C) Caught Interrupt signal. Program interrupted.
b. floatingpointexception.c: Generates and handles a floating point exception in C.
OUTPUT << miaoyi@Hermes
Heading to divide by zero... If we got here, it means the program continued after the floating point error occurred.
c. segfault.c: Generates and handles a segmentation fault in C.
OUTPUT << miaoyi@Hermes
Heading to create some undefined behavior... Caught Segmentation Fault signal. Exiting...

<< Part II >>
NOTE: For this part regarding the details shown below, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/NoChIQ
NOTE: For all operations please install node.js ($ brew install node), and locate into ./project06/JavaScript using the "cd" command.
ROOT: project06/
|__/JavaScript/
|  |__/wordcounter.js
|  |__/wctest.txt
GOAL: The program describes a WordCounter object.
TO TEST $ node wordcounter.js
OUTPUT << % node wordcounter.js wctest.txt
[
  [ 'the', 17 ],    [ 'of', 7 ],
  [ 'and', 6 ],     [ 'was', 5 ],
  [ 'with', 4 ],    [ 'in', 4 ],
  [ 'a', 3 ],       [ 'windows', 3 ],
  [ 'central', 2 ], [ 'portion', 2 ],
  [ 'wings', 2 ],   [ 'were', 2 ],
  [ 'broken', 2 ],  [ 'but', 2 ],
  [ 'up', 2 ],      [ 'had', 2 ],
  [ 'been', 2 ],    [ 'building', 1 ],
  [ 'grey', 1 ],    [ 'lichen-blotched', 1 ]
]

NOTE: For this part regarding the details above-shown, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/NoChIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ