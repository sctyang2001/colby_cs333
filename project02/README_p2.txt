Scottie Yang Miaoyi
CS333 - Project 2
Feb 24, 2021
------------------------------------------------------------
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
------------------------------------------------------------

<<< DIRECTORY LAYOUT >>>
Project02/
|__/task01/
|  |__/task01.yy
|  |__/lex.yy.c
|  |__/example.txt
|__/task02/
|  |__/task02.yy
|  |__/lex.yy.c
|  |__/example.txt
|__/task03/
|  |__/task03.yy
|  |__/lex.yy.c
|  |__/example.txt
|  |__/exampl2.txt
|__/task04/
|  |__/task04.yy
|  |__/lex.yy.c
|  |__/example.c
|__/JavaScript/
|  |__/helloWorld.html
|  |__/simpleAdd.html (EXTENSION)
|  |__/index.js
|__/R/ (EXTENSION)
|  |__/RIntro.rmd
|  |__/RIntro.html

<<< RUNNING SYSTEM >>>
OS - MacOS Monterey 12.1（21C52)
Compiler - XCode.app/c++/4.2.1, Apple clang version 13.0.0 (clang-1300.0.29.30)

<<< Task De-Brief >>>
NOTE: For all operations please locate into ./project02/ using the "cd" command.
<< Part I >>
< Task 1: Encode >
GOAL: Read in from a specified file of some alphabets, print out the shifts of 13 spaces forward in the alphabets.
ROOT: task01/
|__/task01.yy
|__/lex.yy.c
|__/example.txt
TO DETOKENIZE $ flex task01.yy
TO COMPILE $ gcc -o task01 lex.yy.c -ll
TO TEST $ ./task01 example.txt
OUTPUT << miaoyi@Hermes task01 % ./task01 example.txt      
grg
gkg
gjbNFFXNWUFWX
JBJBJBJBJBJB
NUNUN
TPP%

< Task 2: Vowel >
GOAL: Read in from a specified file of some input and print out the number of rows, characters and vocals.
ROOT: task02/
|__/task02.yy
|__/lex.yy.c
|__/example.txt
TO DETOKENIZE $ flex task02.yy
TO COMPILE $ gcc -o task02 lex.yy.c -ll
TO TEST $ ./task02 example.txt
OUTPUT << miaoyi@Hermes task02 % ./task02 example.txt
There are 2 rows in the file.
There are 14 chars in the file.
There are 3 vowels in the file.%

< Task 3: HTMLReader >
GOAL: Read in from a specified file of some HTML tag and text input and print out text with all space and tag stripped.
ROOT: task03/
|__/task03.yy
|__/lex.yy.c
|__/example.txt
|__/example2.txt
TO DETOKENIZE $ flex task03.yy
TO COMPILE $ gcc -o task03 lex.yy.c -ll
TO TEST $ ./task03 example.txt OR $ ./task03 example2.txt
OUTPUT with example << miaoyi@Hermes task03 % ./task03 example.txt
ThisisapagetitleHereisaheader
Hereissomebodytextinaparagraph
Hereisalinktocs.colby.eduinsideaparagraph.%
OUTPUT with example2 << miaoyi@Hermes task03 % ./task03 example2.txt
Project2CS333CS333TopicsNotesHomeworkHomework1Homework2Homework3Homework4Homework5Homework6Homework7Homework8Homework9ProjectsProject1Project2Project3Project4Project5Project6Project7Project8Project9ReferenceMaterialsCS333ProgrammingLanguagesProject2$(funct
...... ......
agelastmodified:document.write(Date(document.lastModified));.% 

< Task 4: Clite Parser >
GOAL: Read in from a specified c file of some input and print out the sequence of strings show-casing the type of input.
ROOT: task04/
|__/task04.yy
|__/lex.yy.c
|__/example.c
TO DETOKENIZE $ flex task04.yy
TO COMPILE $ gcc -o task04 lex.yy.c -ll
TO TEST $ ./task04 example.c
OUTPUT << miaoyi@Hermes task03 % ./task04 example.c
Keyword - int
Identifier - main
Open-paren
Close-paren
Open-bracket
Keyword - int
Identifier - a
Assignment
Integer - 6
Keyword - int
Identifier - b
Assignment
Float - 5.0
Keyword - if
Open-paren
Identifier - a
Comparison - <
Identifier - b
Close-paren
Open-bracket
Identifier - a
Assignment
Identifier - a
Operator - +
Identifier - b
Close-bracket
Close-bracket%

<< Part II >>
ROOT:Project02/
|__/JavaScript/
|  |__/helloWorld.html
|  |__/simpleAdd.html (EXTENSION)
|  |__/index.js
|__/R/ (EXTENSION)
|  |__/RIntro.rmd
|  |__/RIntro.html
NOTE: For this part regarding the above-shown document, please refer to websites below for tutorials.
Part II (JavaScript) TO VISIT https://wiki.colby.edu/x/fgpHIQ
Part II (R) TO VISIT https://wiki.colby.edu/x/hgpHIQ
TO VISIT Scottie's CS333 Project Base Camp https://wiki.colby.edu/x/cApHIQ
