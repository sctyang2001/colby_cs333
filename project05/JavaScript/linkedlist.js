/**
* linkedlist.js: A program that implements the linkedlist in JS.
*
* Scottie YANG Miaoyi
* Mar 20, 2022
*/

class Node {
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor(){
        this.head = null;
    }
    
    ll_push(data){ // Adds a node to the front of the list and stores the given data in the node.
        var node = new Node(data)
        if (this.head == null){
            this.head = node;
        }
        else {
            node.next = this.head
            this.head = node
        }
    }

    ll_pop(){ // Removes the node at the front of the list and returns the associated data.
        this.head = this.head.next;
    }

    ll_append(data){ // Adds a node to the end of the list and stores the given data in the node.
        var node = new Node(data)
        if (this.head == null){
            this.head = node;
        }
        else {
            var current = this.head;
            while (current.next != null){
                current = current.next;
            }
            current.next = node;
        }
    }

    ll_remove(target){ // Removes the first node in the list matches.
        if (this.head.data == target){
            this.head = this.head.next;
        }
        else{
            var current = this.head
            var prev = null
            while(current != null){
                if (target == current.data){
                    prev.next = current.next
                }
                prev = current
                current = current.next
            }
        }
    }

    ll_size(){ // Returns the size of the list.
        if (this.head == null){
            return 0;
        }
        else{
            var current = this.head;
            var size = 1;
            while (current.next != null){
                current = current.next;
                size += 1
            }
            return size;
        }
    }

    ll_free(){ // Removes all of the nodes from the list and freezes the associated data.
        this.head = null;
    }

    ll_map(func){ // Traverses the list and applies the given function to the data at each node.
        var current = this.head;
        while (current != null){
            func(current.data);
            current = current.next;
        }
    }

    ll_print(){ // Print the linkedlist.
        console.log("Printing out LinkedList")
        var current = this.head;
        while (current != null){
            console.log(current.data);
            current = current.next;
        }
    }

    print(data){ // Display.
        console.log(data)
    }
}

//make a linkedlist
var ls = new LinkedList()

//test 'push'
console.log("Push A")
ls.ll_push('A')
console.log("Push B")
ls.ll_push('B')
console.log("Push C")
ls.ll_push('C')
console.log("Print out linkedlist:")
ls.ll_map(ls.print)
console.log(" ")

//test 'pop'
console.log("Pop C")
ls.ll_pop()
console.log("Print out linkedlist:")
ls.ll_map(ls.print)
console.log(" ")

//test 'append'
console.log("Append 100")
ls.ll_append(100)
console.log("Print out linkedlist:")
ls.ll_map(ls.print)
console.log(" ")

//test 'remove'
console.log("Remove 100")
ls.ll_remove(100)
console.log("Print out linkedlist:")
ls.ll_map(ls.print)
console.log(" ")

//test 'size'
console.log("Check size")
console.log(ls.ll_size())
console.log(" ")

//test 'free'
console.log("Check free")
ls.ll_free();
console.log("Print out linkedlist:")
