// $Id: TestSequence.java,v 1.1 2006/09/20 22:00:58 jlang Exp $
// CSI2110 Fall 2006 Laboratory 7: Hash Function Comparison
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
// $Log: TestSequence.java,v $
//
// ==========================================================================
import java.util.ArrayList;

public abstract class HashFunctionAnalysis {
  protected int d_hashTable[]; // hashTable for counting entries only
  protected int d_r; // number of bits for the key

  /**
   * Hash function to be defined
   */
  public abstract int hashFunction( String word );


  /**
   * Create a hashtable for analysis only 
   */
  public HashFunctionAnalysis( int _size ) {
    d_hashTable = new int[_size];
    d_r = (int) Math.ceil(Math.log10(_size)/Math.log10(2));
  }

  /**
   * Bucketing of the hash table counts for a histogram of key
   * distribution
   */
  public int[][] histograms( int _noBuckets ) {
    if ( _noBuckets > d_hashTable.length ) 
      throw new 
	IllegalArgumentException( new 
				  String( "noBuckets > d_hashTable.length"));
    int result[][] = new int[_noBuckets][2];

    float stepSize = ((float)d_hashTable.length) / _noBuckets;
    // calculate number of collisions per histogram bucket
    int h = 0; // histogram bucket counter
    result[0][0] = 0; // lower limit 
    float upperLimit = stepSize; // accumulate up to upperLimit 
    for (int i=0; i<d_hashTable.length; ++i) {
      if ( i > (int)(upperLimit-0.5)  ) {
	++h;
	result[h][0] = i;
	upperLimit += stepSize;
      }
      result[h][1] += d_hashTable[i];
    }
    // return the histogram buckets
    return result;
  }


  /**
   * Simple counting of entries per hashTable slot
   */
  public void frequency(ArrayList<String> _words ) {
    for ( String word : _words ) {
      ++d_hashTable[hashFunction( word )];
    }
    return;
  }




  /**
   * Convenience Function: print histogram on console
   */
  public static void printHistogram( int[][] _histogram ) {
    System.out.println( "Histogram with " + _histogram.length + " buckets:");
    for ( int b=0; b<  _histogram.length; ++b ) {
      System.out.printf( "[%6d]: %10d\n", 
			 _histogram[b][0], 
			 _histogram[b][1] );
    }
    return;
  }


}



