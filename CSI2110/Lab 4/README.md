#Lab 4
###Binary Tree Traversal and Euler Tours

Study the binary tree implementation of Goodrich et al. The approach consists of an ADT binary tree `BinaryTree.java` extending the ADT tree `Tree.java` which is implemented with a linked list `LinkedBinaryTree.java`. These classes are all part of the net.datastructures package which is contained (as far as required) in the zip archive for this lab.

Run the code provided in the skeleton class Lab4. It will build a small binary tree and print the nodes onto the console. Draw this binary tree on a piece of paper.

Write down the nodes which would be visited by the pre-order, in-order and post-order traversal algorithms. Determine the height of the tree.

Study the code in the skeleton `Lab4.java`. You have to implement the missing sections such that `Lab4.java` prints the nodes visited by the pre-order, in-order and post-order traversals. Additionally, you need to print the height of the tree. You will have to extend the EulerTour class from the net.datastructure package to achieve these outputs.

Hints:

The use of the EulerTour class may be not obvious at first. It is an abstrcat class and needs to be extended by

Implementing the `execute( BinaryTree T)` method.
Overwriting one or several of the visit methods, e.g., `visitLeft(Position v, TourResult r)`.
The skeleton `Lab4.java` already contains a partial example on how to do this with an anonymous class. I.e., defining the sub-class of EulerTour and instantiating this subclass but not naming it. The `execute( BinaryTree T)` method is defined but no visit method is overwritten.
Summary


- Download the Lab4.zip archive and study the following files in net.datastructures:
`BinaryTree.java`, `Tree.java`, `LinkedBinaryTree.java`

- Run the Skeleton Code
`Lab4.java`

- Draw the tree and list the nodes visited by
Pre-order traversal,
In-order traversal, and
Post-order traversal.

- Determine the height of the tree.

- Study EulerTour.java

- Implement the indicated sections in `Lab4.java`
Print nodes in pre-order traversal;
Print nodes in in-order traversal; and
Print nodes in post-order traversal.
Calculate and print the height of the tree.

© Jochen Lang