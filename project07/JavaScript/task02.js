/**
* task02.js: The program demonstrates an experiment with automatic memory management.
*
* Scottie YANG Miaoyi
* Apr 29, 2022
*/

// Explores the automatic memory management.
for (let i= 0; i< 25; i++){
    var start = new Date().getTime(); // Timer initialization.

    var array = new Array(1000000); // Allocation
    var string = "Scottie!";
    var object = {};
    var number = 12345678;
    var boolean = true;

    array, string, object, number, boolean = null // Deletion

    var end = new Date().getTime();
    console.log('The execution time is ' + (end-start) + 'ms.');
}
