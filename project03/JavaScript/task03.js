/**
* task03.js: This program introduces build-in types and aggregate types.
*
* Scottie YANG Miaoyi
* Mar 4, 2022
*/

/* The following code demonstrates operations in JavaScript.
*/
console.log("My age is: " + 19); // Outputs
console.log(10%5); // Outputs 0
console.log(10/5); // Outputs 2
console.log(10-5); // Outputs 5

/* The following code demonstrates constructing arrays.
*/
// An example of an Array
var countries = ["China", "Russia", "USA"];
console.log(countries[2]); //outputs: "USA".

// An example of a class, defines a class rectangle with two main fields:
// defines a get function that returns the area of a rectangle.
class Rectangle {
    constructor(height, width) {
        this.height = height;
        this.width = width;
    }

    get calcArea(){
        return this.height * this.width;
    }
}
const square = new Rectangle(10, 10);
console.log(square.calcArea); // Prints out 100