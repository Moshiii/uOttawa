# Lab 3
###Adapter Pattern and Node List ADT

As discussed in class a doubly-linked list provides a natural implementation of the Node List ADT.

The Java Collections Framework does not provide a NodeList interface. In this lab you will need to adapt the LinkedList implementation of the Java Collections Framework to a NodeList and analyze this approach.

The Java Collections Framework is well documented in the this tutorial by Sun. The Collections Framework provides two list implementations: `java.util.ArrayList` and `java.util.LinkedList` . You should run the simple example program TestListImplementation.java which compares the two list implementations. The test program is contained in the archive lab3.zip.

Your NodeList should hold a sentence consisting of strings which your main program should print in order. See the main program in Sentence.java for clarification.

Your NodeList adapter class needs to implement the methods specified in this `NodeList.java` skeleton class. You may assume that each node in your NodeList has a unique reference but may contain several objects where a call to "equals()" will return true.

Consider the performance of your adaptor class. Which methods have not the expected performance of a NodeList implementation and why?

Summary

- Look at the Java Collections Framework tutorial
- Download the archive lab3.zip
- Study and run `TestListImplementation.java`
- Look at `NodeList.java`
- Implement indicated methods and test your code with `Sentence.java`
- Analyze the behaviour of your adapter class

Â© Jochen Lang