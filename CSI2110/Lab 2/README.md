#Lab 2

###1) Stacks. Array and linked list implementation of stacks.

Download the archive Lab2.zip and extract subdirectory stack with the stack implementation contained in the following files

 - Stack.java
 - Node.java
 - NodeStack.java
 - ArrayStack.java
 - StackEmptyException.java
 - FullStackException.java

The archive also contains the files `tryStack1.java` and `tryStack2.java`

- Compile tryStack1 and run it
- Compile tryStack2 and run it

###2) Doubly Linked Lists in Java

Extract the subdirectory `dLinkList` from the archive Lab2.zip with the implementation of the doubly-linked list contained in the following files.

- ListNode.java
- DLinkedList.java

In `DLinkedList.java` implement the following methods:

- `InsertNode(ListNode nNode, ListNode pAfter)`
inserts the node nNode after node pAfter in the current list
- `RemoveNode(ListNode nNode)`
removes node nNode from current list

Compile `TestDLinkedList.java` and run it

###3) Checking Balanced Brackets in Expressions with Stacks

Extract the subdirectory balance from the archive Lab2.zip with the implementation of the stack ADT with an array list contained in the following files:

- Stack.java
- ArrayStack.java
- StackEmptyException.java
- StackFullException.java

The archive also contains the file `bracketsBalance.java` in which you should implement the following method:

- `boolean bBalance (String exp)`
that evaluates exp for balanced brackets and returns true (if balanced) and false otherwise
use the stack implementation in `ArrayStack.java`.

Compile `bracketsBalance.java` and run it with different expressions