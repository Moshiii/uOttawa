#CSI2110 - Lab 1

###0) Test your IDE (optional)

In case you are uncertain if your prefered Java development environment works as expected, the archive `Lab1.zip` contains `HelloWorld.java` for testing.

###1) Singly Linked List

Download the archive `Lab1.zip` and extract the singly linked list implementation contained in the following files
`LinkList.java`
`Node.java`
Compile and run LinkList.java and study its behaviour.
###2) Doubly Linked Lists

Change the singly-linked-list to a doubly-linked-list by changing `Node.java` to `DNode.java`.
Change the `LinkList` class to work with `DNode`, in particular, adapt the implementation of the `void LinkList.deleteLast()` method.
###3) Using Generics

The archive `Lab1.zip` also contains the file `GNode.java` which implements a node for a singly-linked-list as before but instead of storing a reference to an Object, it uses a generic element.
Adapt the original `LinkList` class to use the generic `Gnode` class.