/**
* cstk.c: The program contain contain the implementation 
* of the basic functions declared in the cstk.h file.
* (This file is linked with "cstk.h".)
*
* Scottie YANG Miaoyi
* Mar 4, 2022
*/

#include "cstk.h"
int CSTK_MAX = 50;

Stack *stk_create(int size) // Creates a stack in memory with the size specified by the int value.
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = 0;
    stack->stack = (int *)malloc(size * sizeof(int));
    return stack; 
}

void stk_push(Stack *S, int n) // Adds a new value to the top of the stack.
{
    if (S->top < CSTK_MAX)
        S->stack[S->top++] = n;
    else
        fprintf(stderr, "Error: the stack object is full.\n");
}

int stk_pop(Stack *S) // Removes a value from the top of the stack.
{
    int val = S->stack[S->top];
    if (S->top == 0)
        fprintf(stderr, "Error: the stack object is empty.\n");
    else{
        S->top--;
    }
    return val;
}

void stk_display(Stack *S, int n) // Prints out the list in the reverse order if the int value is 1, otherwise, prints out in the original order
{
if (n == 1) {
    for (int j = S->top - 1; j >= 0; j--){
        printf("%d ", S->stack[j]);
    }
    printf("\n");
} else {
    for (int i = 0; i < S->top; i++){
        printf("%d ", S->stack[i]);
    }
    printf("\n");
}
}

void stk_destroy(Stack *S) // Recycles the stack.
{
    free(S->stack);
    free(S);
}