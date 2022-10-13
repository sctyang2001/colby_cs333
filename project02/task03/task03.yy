/** 
* HTMLReader: Read in from a specified file of some HTML tag and 
* text input and print out text with all space and tag stripped.
* 
* Scottie YANG Miaoyi
* Feb 22, 2021
* 
* TO DETOKENIZE $ flex task03.yy
* TO COMPILE $ gcc -o task03 lex.yy.c -ll
* TO TEST $ ./task03 example.txt OR $ ./task03 example2.txt
*/
    

%%

"<p>" {printf("\n");} // match <p>, if detected, change line
"<"(!--)*[^>]*(--)*> // if anything enclosed in <>, dismiss it
" " // if any space ignore it
\n // if any newline ignore it
\t // if any tab ignore it
. {printf("%s", yytext);} // else note the character and print it later

%%    
/* Main function serves as a flex catalyst and print machine.
*/ 
int main(int argc, char*argv[])
{
    if (argc > 1) // If there is more than one argument, pass the file in.
        yyin = fopen(argv[1], "r" );  
    yylex(); 
  
    return 0;
}