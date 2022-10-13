/** 
* Encode: Read in from a specified file of some alphabets
* print out the shifts of 13 spaces forward in the alphabets.
* 
* Scottie YANG Miaoyi
* Feb 21, 2021
*
* TO DETOKENIZE $ flex task01.yy
* TO COMPILE $ gcc -o task01 lex.yy.c -ll
* TO TEST $ ./task01 example.txt
*/

%%

[a-z] {printf("%c", (yytext[0]-'a'+13)%26+'a');} // yytext to be processed with ASCII
[A-Z] {printf("%c", (yytext[0]-'A'+13)%26+'A');}
. /* skip all other input */

%%
/* Main function serves as a flex catalyst.
*/ 
int main( int argc, char *argv[] ) {
    if (argc > 1) // If there is more than one argument, pass the file in.
        yyin = fopen(argv[1], "r" );
    yylex(); // Function of flex, reads input until it is exhausted.
    return 0;
}