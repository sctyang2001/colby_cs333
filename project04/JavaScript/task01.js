/**
* task01.js: A program that uses all these control flow statements.
*
* Scottie YANG Miaoyi
* Mar 11, 2022
*/

/* The following code demonstrates for loop. 
*/
var i;
for (i=0; i<3; i++){
    console.log(i);
}

/* The following code demonstrates while loop. 
*/
var j=0;
while (j<4){
    console.log(j);
    j++;
}

/* The following code demonstrates do..while loop. 
*/
var k=0;
do {
    console.log(k);
    k++;
} while (k<5)

/* The following code demonstrates if statement. 
*/
let a = 5;
if(a<6) console.log("a is less than 6.")
else console.log("a is larger than or equal to 6.")

/* The following code demonstrates switch statement. 
*/
let are_you_mad = 1;
switch(are_you_mad){
    case 0:
        console.log("No, what the hell.");
        break;
    case 1:
        console.log("Yes, I am crazyyyyiaa!");
        break;
}

/* The following code demonstrates ternary statement. 
*/
console.log(statement = 10>9 ? "Yes":"No");