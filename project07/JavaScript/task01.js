
// The following code demonstrates cyclic reference.
let a = {enemy:{},};
let b = {enemy:{},};
a.enemy = b;
b.enemy = a;

// The following code demonstrates memory leak caused by forgotten timer interval.
var c = 0.07;
const interval = setInterval(function(){x+=0.01},500); // a forgotten interval
clearInterval(interval); // clearing the interval by hand to get it garbage-collected 