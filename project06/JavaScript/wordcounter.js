/**
* wordcounter.js: The program describes a WordCounter object.
*
* Scottie YANG Miaoyi
* Apr 16, 2022
*/

// Read in file.
function readFile(file_name){
    const fs = require('fs')
    var arr;
    let data = fs.readFileSync(file_name, {encoding:'utf8', flag:'r'})
    // Convert to lowercase
    data = data.toLowerCase()
    // Split by space, comma, and period
    arr = data.toString().split(/[,. ]+/);
    return arr
}

function main(){
    var file_name = process.argv
    var arr;
    arr = readFile(file_name[2]);

    var dict = {};
    for (index = 0; index < arr.length; index++) {
        //if the word is not in the dictionary
        if (!dict[arr[index]]) {
            dict[arr[index]] = 1
        }
        //if the word is already in the dictionary
        else{
            dict[arr[index]]++;
        }
    }

    // Create an item array.
    var items = Object.keys(dict).map(function(key) {
        return [key, dict[key]];
    });

    // Sort the array based on the second element.
    items.sort(function(first, second) {
        return second[1] - first[1];
    });

    // Create a new array with only the first 20 items.
    console.log(items.slice(0, 20));
}

main()

