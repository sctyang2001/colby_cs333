/** 
* Vowel: Read in from a specified file of some input and 
* print out the number of rows, characters and vocals.
* 
* Scottie YANG Miaoyi
* Feb 22, 2021
* 
* TO DETOKENIZE $ flex task02.yy
* TO COMPILE $ gcc -o task02 lex.yy.c -ll
* TO TEST $ ./task02 example.txt
*/
    
    int charcount = 0;
    int vowcount = 0;
    int linecount = 0;

%%

[AEIOUaeiou] {charcount++; vowcount++;} // Initialize counts.
. {charcount++;}
\n {linecount++;}

%%
/* Main function serves as a flex catalyst and print machine.
*/ 
int main( int argc, char *argv[] ) {
    if (argc > 1) // If there is more than one argument, pass the file in.
        yyin = fopen(argv[1], "r" );  
    yylex(); // Function of flex, reads input until it is exhausted.
    printf("There are %d rows in the file.\n", linecount);
    printf("There are %d chars in the file.\n", charcount);
    printf("There are %d vowels in the file.\n", vowcount);
    return 0;
}