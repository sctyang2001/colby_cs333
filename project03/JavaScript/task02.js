/**
* task02.js: This program demonstrates basic operation in js using Binary Search.
*
* Scottie YANG Miaoyi
* Mar 4, 2022
*/

/* The following code demonstrates binary search. 
*/
function binarySearch(array, key) {
    var lo = 0,
        hi = array.length - 1,
        mid,
        element;
    while (lo <= hi){
        mid = Math.floor((lo + hi) / 2, 10) ;
        element = array[mid];
        if (element < key){
            lo = mid + 1;
        } else if (element > key) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

console.log(binarySearch([1,5,6,8,99,133,466,1111],99)); //Outputs: 4 (index of 99)