// ==========================================================================
// $Id: Lab4.java,v 1.1 2006/10/02 14:38:58 jlang Exp $
// CSI2110 Lab code testing list interfaces 
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   SITE, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada. 
//   http://www.site.uottawa.ca
// 
// Creator: jlang (Jochen Lang)
// Email:   jlang@site.uottawa.ca
// ==========================================================================
// $Log: Lab4.java,v $
// Revision 1.1  2006/10/02 14:38:58  jlang
// Bring lab1-5 into cvs
//
//
// ==========================================================================
import net.datastructures.*;
import java.util.Iterator;

class Lab4 {

  /** build a small (fixed) binary tree - 6 nodes */
  public static BinaryTree<String> buildTree() {
    LinkedBinaryTree<String> bTree=new LinkedBinaryTree();
    bTree.addRoot("node0");
    Position<String> r = bTree.root();
    bTree.insertLeft(r,"node1");
    bTree.insertRight(r,"node2");
    bTree.insertLeft(bTree.left(bTree.root()),"node3");
    bTree.insertRight(bTree.left(bTree.root()),"node4");
    bTree.insertRight(bTree.left(bTree.left(bTree.root())),"node5");
    bTree.insertLeft(bTree.right(bTree.left(bTree.root())),"node6");
    return bTree;
  }

  /** print all nodes of a tree with the nodes' children (if any) */
  public static void print( BinaryTree<String> bTree ) {
    System.out.print(" node\t type\t\tleft children\t");
    System.out.println("right children\tcomment");
    for ( Position<String> bNode : bTree.positions() ) {
      System.out.print(bNode.element()+"\t");
      if(bTree.isInternal(bNode)) {
	System.out.print(" Internal"+"\t");
	if(bTree.hasLeft(bNode)) {
	  System.out.print(bTree.left(bNode).element()+"\t\t");
	} else {
	  System.out.print("\t\t");
	}
	if (bTree.hasRight(bNode)) {
	  System.out.print(bTree.right(bNode).element()); 
	} 
      }else {	
	System.out.print(" External"+"\t");
      }
      if(bTree.isRoot(bNode)) {
	System.out.print("\t \tRoot"); 
      }
      System.out.println();
    }
  }
  
  public static void main(String [] args){
    BinaryTree<String> bTree = Lab4.buildTree();
    Lab4.print( bTree );

    // Pre-Order Traversal
    EulerTour<String,String> et = new EulerTour<String,String>(){
      public String execute( BinaryTree<String> bTree ) {
	init(bTree);
	eulerTour(tree.root());
	return null;
      }
      protected void visitLeft(Position<String> bNode, 
			       TourResult<String> r) {
	System.out.print( bNode.element() + " " );
	return;
      }
    };
    System.out.print("Pre-Order: ");
    et.execute(bTree);
    System.out.println();

    // In-Order Traversal
    et = new EulerTour<String,String>(){
      public String execute( BinaryTree<String> bTree ) {
	init(bTree);
	eulerTour(tree.root());
	return null;
      }
      protected void visitBelow(Position<String> bNode, 
			       TourResult<String> r) {
	System.out.print( bNode.element() + " " );
	return;
      }
    };
    System.out.print("In-Order: ");
    et.execute(bTree);
    System.out.println();
    
    // Post-Order Traversal
    et = new EulerTour<String,String>(){
      public String execute( BinaryTree<String> bTree ) {
	init(bTree);
	eulerTour(tree.root());
	return null;
      }
      protected void visitRight(Position<String> bNode, 
			       TourResult<String> r) {
	System.out.print( bNode.element() + " " );
	return;
      }
    };
    System.out.print("Post-Order: ");
    et.execute(bTree);
    System.out.println();

    // Height of the tree 
    EulerTour<String,Integer> height = new EulerTour<String,Integer>(){
      public Integer execute( BinaryTree<String> bTree ) {
	init(bTree);
	Integer res = eulerTour(tree.root());
	return res;
      }
      protected void visitRight(Position<String> bNode, 
			       TourResult<Integer> r) {
	r.out = 0;
	if ( !tree.isExternal( bNode )) {
	  if ( r.left != null  ) {
	    r.out = Math.max( r.left, r.out );
	  }
	  if ( r.right != null  ) {
	    r.out = Math.max( r.out, r.right );
	  }
	  // Auto boxing will cause the compiler 1.5.0_08 to fail here
	  r.out = new Integer( r.out + 1 );
	}
	return;
      }
    };
    System.out.println( "Height of Tree: " + height.execute(bTree) );
  }
}