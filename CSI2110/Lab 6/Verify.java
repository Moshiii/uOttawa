// ==========================================================================
// $Id: Verify.java,v 1.1 2006/10/24 00:24:40 jlang Exp $
// CSI2110 Lab code: BST height comparison
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
// $Log: Verify.java,v $
// Revision 1.1  2006/10/24 00:24:40  jlang
// Added Lab 6
//
//
// ==========================================================================
import net.datastructures.AVLTree;
import net.datastructures.BinarySearchTree;
import net.datastructures.BinaryTree;
import net.datastructures.Position;
import net.datastructures.Entry;
import net.datastructures.EulerTour;

public class Verify {
  protected int d_totalHeightAVL;
  protected int d_totalHeightBST;
  protected int d_minAVL, d_maxAVL;
  protected int d_minBST, d_maxBST;
  protected int d_noTrees;


  /**
   * Initialize internal height counters
   */
  protected void initCounters(int _maxHeight, int _noTrees) {
    d_minAVL = _maxHeight+1;
    d_maxAVL = -1;
    d_minBST = _maxHeight+1;
    d_maxBST = -1;
    d_totalHeightAVL = 0;
    d_totalHeightBST = 0;
    d_noTrees = _noTrees;
    return;
  }


  /**
   * Update internal height counters after new tree has been constructed
   */
  protected void updateCounters(int _heightAVL, int _heightBST ) {
    d_totalHeightAVL += _heightAVL;
    d_totalHeightBST += _heightBST;
    if ( _heightAVL > d_maxAVL ) d_maxAVL = _heightAVL;
    if ( _heightAVL < d_minAVL ) d_minAVL = _heightAVL;
    if ( _heightBST > d_maxBST ) d_maxBST = _heightBST;
    if ( _heightBST < d_minBST ) d_minBST = _heightBST;
    return;
  }


  /**
   * Print statistics about the trees generated
   */
  public void printStatistics() {
    System.out.printf( "%10d %10d %10.3f %10d %10d %10.3f %10.3f\n", 
		       d_minBST,
		       d_maxBST, 
		       ((double)d_totalHeightBST)/d_noTrees,
		       d_minAVL,
		       d_maxAVL, 
		       ((double)d_totalHeightAVL)/d_noTrees,
		       Math.log(d_noTrees));
  }


  /**
   * Generate _nTrees random trees each with _noNodes
   */
  public void randomTrees( int _noNodes, int _nTrees ) {
    // Initialize minmum and maximum counters
    initCounters( _noNodes, _nTrees );
    // generate _nTrees and update statistics
    for(int i=0; i<_nTrees; ++i) { 
      // AVL and BST trees with same nodes
      AVLTree<Integer,Integer> treeAVL = new AVLTree<Integer,Integer>(); 
      BinarySearchTree<Integer,Integer> treeBST = 
	new BinarySearchTree<Integer,Integer>(); 

      // loop to insert _noNodes keys into tree
      int count = 0;
      do {
	// create random key between 0 and the maximum integer
	int randKey=(int) (Math.random()*Integer.MAX_VALUE);
	// make sure the generated random key is not used before!!
	if(treeAVL.find(randKey) == null) {
	  // insert into AVL
	  treeAVL.insert(randKey, null); 
	  // insert into BST
	  treeBST.insert(randKey, null);
	  // next key
	  ++count;
	}
      } while ( count < _noNodes );
      updateCounters( height( treeAVL ), height( treeBST));
    }
    return;
  }


  /**
   * Adapt the Euler tour to calculate height (see Lab 4)
   * Note: BST and AVL trees are binary trees
   */
  public <T> int height( BinaryTree<T> bTree ) {
    // Height of the tree 
    EulerTour<T,Integer> height = new EulerTour<T,Integer>(){
      public Integer execute( BinaryTree<T> bTree ) {
	init(bTree);
	Integer res = eulerTour(tree.root());
	return res;
      }
      protected void visitRight(Position<T> bNode, 
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
    // System.out.println( "Height of Tree: " + height.execute(bTree) );
    return height.execute(bTree);
  }

  /**
   * Entry point: compare height statistics 
   * of different size BST and AVL trees
   */
  public static void main(String[] _argv) {
    Verify test = new Verify();
    int numNodesStart = 2;
    int numSteps = 8;

    if ( _argv.length > 0 ) numSteps = Integer.valueOf( _argv[0] );

    System.out.println( "Height Comparison: with and without AVL balancing" );
    System.out.printf( "%6s %10s %10s %10s %10s %10s %10s %10s\n", 
		       "N", "min", "max", "avg", 
		       "min", "max", "avg", "log(N)");

    int numNodes = numNodesStart;
    for ( int i=0; i<numSteps; ++i ) {
      // create regular BST and AVL search trees
      test.randomTrees( numNodes, Math.max( 10, numNodes<<2) );
      // print statistics
      System.out.printf( "%6s ", numNodes );
      test.printStatistics();
      numNodes <<= 1; // multiply by 2
    }
    return;
  }

}