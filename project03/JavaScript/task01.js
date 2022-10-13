/**
* task01.js: This program demonstrates naming conventions and identifier scoping,
* it also serves as the extension of shadowing and hoisting.
*
* Scottie YANG Miaoyi
* Mar 4, 2022
*/

/* The following code demonstrates naming conventions 
*/
//Acceptable variables names:
var my_name = "Maan";
var my_age = 19;
var _collegeYear = 2020;
var $collegeName = "Colby College";

/* The following code demonstrates identifier scoping. 
*/
var test = 5;
for (var i = 0; i < 10; i++) {var count = 0;}

function foo(){
    var local = 4;
}

console.log ("Global variable: " + test); //outputs: 5.
console.log ("Loop variable: " + count); //outputs: O.
//console.log ("local variable: " + local); // outputs: Error: Local is not defined.

//Block access:
{
    var test1 = 4;
}
{
    let test2 = 5;
}

console.log ("Without let: " + test1); // outputs 4.
// console.log ("With let: " + test2); // outputs an error: test2 is not defined.

/* The following code demonstrates shadowing (extension). 
*/
// Partl
var test = "I'm global";
function testScope(){
    var test = "I'm local";
    console.log(test);
}
testScope(); // output: I'm local
console.log(test); // output: I'm global

//Part2:
var test = "I'm global";
function testScope(){
    test = "I'm local";
    console.log(test);
}
console.log(test); // output: I'm global
testScope(); // outout: I'm local
console.log(test); // output: I'm local (the global variable is reassigned)

/* The following code demonstrates hoisting (extension). 
*/
console.log (state);// output: undefined
var state = "ready";
