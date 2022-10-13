/** 
* Clite Parser: Read in from a specified c file of some input and 
* print out the sequence of strings show-casing the type of input.
* 
* Scottie YANG Miaoyi
* Feb 23, 2021
*
* TO DETOKENIZE $ flex task04.yy
* TO COMPILE $ gcc -o task04 lex.yy.c -ll
* TO TEST $ ./task04 example.c
*/
    
DIGIT   [0-9]

%% 

{DIGIT}*    {
            printf("Integer - %s\n", yytext );
            }
{DIGIT}+"."{DIGIT}*  {
            printf("Float - %s\n", yytext);
            }
if|else|while|for|int|float {
            printf("Keyword - %s\n", yytext);
            }
==|<|>|<=|>= {
            printf("Comparison - %s\n", yytext);
            }

=           {
            printf("Assignment\n");
            }
"+"|"-"|"*"|"/" {
            printf("Operator - %s\n", yytext);
        }           
"{"     {
            printf("Open-bracket\n");
        }
"}"     {
            printf("Close-bracket\n");
        }
"("     {
            printf("Open-paren\n");
        }

")"     {
            printf("Close-paren\n");
        }

[a-zA-Z]+ {
            printf("Identifier - %s\n", yytext);
        }
\n\\
\n
.

%%
/* Main function serves as a flex catalyst and print machine.
*/ 
int main ( int argc, char *argv[] ) {	
    if (argc > 1) // If there is more than one argument, pass the file in.
        yyin = fopen(argv[1], "r" );
    yylex(); // Function of flex, reads input until it is exhausted.
    return 0;

}