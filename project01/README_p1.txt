Scottie Yang Miaoyi
CS333 - Project 1
Feb 13, 2021

/// Running System ///
OS - MacOS Monterey 12.1（21C52
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

/// Directory Layout ///
Project01/
|__/README.txt
|__/Task01.c
|__/Task02.c
|__/Task03.c
|__/Task04.c
|__/Task05.c

/// Task De-Brief ///
-- Part I --
For all operations please locate into ./Project01/ using the "cd" command.
| Task 1 |
GOAL: The program explores how memory is excessively allocated and freed.
TO COMPILE $ gcc -o task01 Task01.c
TO RUN $ ./task02
OUTPUT:
char 0: 61
short 0: E0
short 1: 15
int 0: 20
int 1: F4
int 2: 0E
int 3: 00
long 0: 01
long 1: A5
long 2: 45
long 3: 9B
long 4: 01
long 5: 00
long 6: 00
long 7: 00
float 0: 56
float 1: 0E
float 2: 49
float 3: 40
double 0: D9
double 1: 07
double 2: 14
double 3: 8B
double 4: 0A
double 5: BF
double 6: 05
double 7: 40
QUESTION ANSWERS:
a. This machine is a Little-Endian Machine.
b. We will take int as an example. The program defines int i = 980000, and we translate into hex of 0x000EF420. However, the machine visit the address starting from 20 (the rightmost byte) instead of 00 (the leftmost byte), therefore it is a Little-Endian.

| Task 2 | 
GOAL: The program explores how data is stored in the memory separately.
TO COMPILE $ gcc -o task02 Task02.c
TO RUN $ ./task02
OUTPUT (with i<150):
current: 0 - C8
current: 1 - 26
current: 2 - 98
current: 3 - BA
current: 4 - F7
current: 5 - 7F
current: 6 - 00
current: 7 - 00
current: 8 - 01
current: 9 - A5
current: 10 - 45
current: 11 - 9B
current: 12 - 01
current: 13 - 00
current: 14 - 00
current: 15 - 00
current: 16 - 20
current: 17 - F4
current: 18 - 0E
current: 19 - 00
current: 20 - E0
current: 21 - 15
current: 22 - 00
current: 23 - 61
current: 24 - 28
current: 25 - A8
......
current: 147 - 15
current: 148 - 01
current: 149 - 00
OUTPUT (with i<5000):
......
zsh: segmentation fault
QUESTION ANSWERS:
a. If we ask for too many memory, the system denies it, giving back a segmentation error.
b. Yes, from line 16-23 we see:
current: 16 - 20
current: 17 - F4
current: 18 - 0E
current: 19 - 00 // Line 16-19 is int i = 980000's hex Little-Endian.
current: 20 - E0
current: 21 - 15 // Line 20-21 is short sh = 5600's hex Little-Endian.
current: 22 - 00 // This line seems to simply be a fill-up space since line 23 is an odd char hex.
current: 23 - 61 // Line 23 is char c = 'a''s hex Little-Endian.

| Task 3 | 
GOAL: The program explores how memory is excessively allocated and freed in the memory.
NOTE: This program may cause overheat, intervene promptly and timely to avoid this to happen. This program contains two stage, the first stage is to delete the "free(c)" sentence in the code and check the system memory, the second stage is to add it back and run it again.
TO COMPILE $ gcc -o task03 Task03.c
TO RUN $ ./task03
TO STOP use key Ctrl^+C
NO OUTPUT EXPECTED AND GENERATED
QUESTION ANSWERS: This program, without the "free(c)" sentence, is a king of eating the memory. I could see from Activity Monitor that it was eating up the memory in a speedy manner (around 50M/second) while fan started blowing. I have to cut it halfway to prevent the computer to overheat. In the second stage, after "free(c)" is introduced after every allocation, I could see the memory does not have dramatic change over time, as it was balancing itself dynamically and memory is freed in a timely manner.

| Task 4 | 
GOAL: The program explores how struct is stored in memory.
TO COMPILE $ gcc -o task04 Task04.c
TO RUN $ ./task04
OUTPUT:
Yang(ID) 0: 4D // Line 0 is char Yang->gender = 'M''s hex Little-Endian.
Yang(ID) 1: 00 // This line seems to simply be a fill-up space since line 0 is an odd char hex.
Yang(ID) 2: D1
Yang(ID) 3: 07 // Line 2-3 is short Yang->byear = 2001's hex Little-Endian.
Yang(ID) 4: 9E
Yang(ID) 5: 00 // Line 4-5 is short Yang->weight = 158's hex Little-Endian.
QUESTION ANSWERS:
a. No. There is a gap between line 0 char and line 2-3 short in line 1.
b. Yes, there is one byte 00 in line 1. I thought the total struct would take up 5 bytes but it turned out to be 6 bytes, since the line 0 char only has one byte and the system automatically fills that spare odd space between it and line 2-3 short with an empty byte 00.

| Task 5 | (Extension included: 3)
GOAL: This program checks if the system let the strcpy function overflow.
TO COMPILE $ gcc -o task05 Task05.c
TO RUN $ ./task05 (String), note that you MUST put ONE string after "./task05" to serve as a command-line argument. See example below:
CORRECT Example 1: $ ./task05 PutaGuapa
CORRECT Example 2: $ ./task05 YoyoHowAreYouTodayIAmFineThankYou
FALSE Example 1: $ ./task05 PutaGuapa Aloha
FALSE Example 2: $ ./task05
OUTPUT (with CORRECT Example 1): safe
OUTPUT (with CORRECT Example 2): zsh: illegal hardware instruction
OUTPUT (with FALSE Example 1): Too many arguments supplied.
OUTPUT (with FALSE Example 2): One argument expected.
QUESTION ANSWERS:
I made the string length to be 15, so anything over char length 15 will have a crash on this compiler saying "illegal hardware instruction" while those under 15 will have "safe" displayed, since int variable "overflow" is still 0 and is not influenced.

-- Part II --
Please check my Wiki page on: https://wiki.colby.edu/x/RQklIQ.