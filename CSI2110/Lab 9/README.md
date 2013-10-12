#Lab 9
###Adjacency List Implementation of a Graph and DFS

Download the archive Lab9.zip and extract the `SimpleGraph` application. The application reads an edge-list from a file and constructs a Graph. The Graph is stored as `AdjacencyListGraph`. The application simple prints all the vertices followed by all the edges. The archives also contain two graph files which you can use as input for the application:

- graph.txt
- graph2.txt


####New Graph

Define a new graph in a textfile and print it with the application.

####Study the Goodrich et al. Implementation

Study the `AdjacencyListGraph` implementation of the Graph ADT by Goodrich et al. Keep in mind the structure discussed in class. Notice that the adjacency lists are implemented in the inner class `MyVertex` and the references from the edges in the inner class `MyEdge`. The Graph ADT does not define any traversal method. The traversal of graphs is implemented with a separate class DFS. These classes are all part of the net.datastructures package which is contained (as far as required) in the zip archive for this lab.

####Printing with Generic DFS (Advanced; will be covered on Friday)

The program `SimpleGraph` has a routine `void printDFS( String vert )` which currently does nothing. Please implement this routine by sub-classing DFS. An anonymous inner class would be appropriate. The routine should print the vertices as they are visited by the traversal: once when they are first visited and a second time when a vertex is finished.