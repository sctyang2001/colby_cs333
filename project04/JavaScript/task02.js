/**
* task02.js: A program to show how are functions treated in the language as a data type.
*
* Scottie YANG Miaoyi
* Mar 11, 2022
*/

/* The following code demonstrates a display function. 
*/
function display(a){
    console.log("Displayed from", a);
}

/* The following code demonstrates a call function, calling any given function. 
*/
function call(m,func){
    func(m);
}

var alias = display; // Define a function as a variable.

call("original", display);
call("alias", alias);