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
import java.io.BufferedReader;
import java.io.StreamTokenizer;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.ArrayList;
import java.util.ListIterator;


public class TestHashFunc {
  final static boolean DEBUG = true;

  /**
   * Read all the words in a text file
   * -- throw away any numbers
   */
  public static void readTextFile( String _fileName, 
				   ArrayList<String> _strings )
    throws java.io.IOException 
  {
    BufferedReader reader = new 
      BufferedReader(new FileReader(_fileName));
    StreamTokenizer st = new StreamTokenizer(reader);
    for (int token = st.nextToken(); 
	 token !=  StreamTokenizer.TT_EOF;
	 token = st.nextToken()) 
      {
	switch (token) {
	case StreamTokenizer.TT_WORD:
	  _strings.add(_strings.size(), st.sval);
	  break;
	default:
	  // do nothing
	  break;
	}
      }
    reader.close();
    return;
  }

  /**
   * Output to console: 7 words per line
   */
  public static <E> void printList( ArrayList<E> _list ) {
    int wc = 0;
    for ( ListIterator<E> iter = _list.listIterator();
	  iter.hasNext(); ) {
      System.out.print( iter.next() + " ");
      if ( (wc+1)%7==0 ) { 
	System.out.println();
	wc = 0;
      }
      wc++;
    }
    System.out.println();
    return;
  }

  /** Helper method:
   * Read a integer number from the console
   */
  public static int readNumber( String _question ) 
    throws IOException, NumberFormatException {
    System.out.print( _question );
    BufferedReader reader = 
      new BufferedReader(new InputStreamReader ( System.in ));
    return Integer.parseInt(reader.readLine());
  }


  /**
   * Program entry point: expects name of a text file
   */
  public static void main(String[] argv) {
    if ( argv.length < 1 ) 
      System.err.println( "Usage: java TestHashFunc fileName" );

    ArrayList<String> words = new ArrayList<String>();
    
    int tSize = 9; // default size
    try {
      readTextFile( argv[0], words );
      System.out.println("\nStrings:\n");
      printList( words );
      // Test how the words would distribute in the HashTable
      tSize = readNumber( "\nSize of hash table? ");

    } catch ( java.io.IOException ioE ) {
      System.err.println(ioE + ": " + argv[0]);
    }

    // Extend HashFunctionAnalysis with the hash function to test
    HashFunctionAnalysis hfa = new HashFunctionAnalysis( tSize ){
	public int hashFunction( String _word ) {
	  // ensure key is long enough 
	  String key = _word + "       ";
	  // change to bytes
	  byte h1Key[] = key.getBytes();
	  // turn the first d_r bits into an int
	  int hKey = 0;	  
	  int pos = d_r;
	  short mask = 0x80;
	  int byteNum = 0;
	  while ( pos > 0 ) {
	    if ( DEBUG ) {
	      System.out.print( (h1Key[byteNum]+128) + " # " );
	      System.out.println( ((h1Key[byteNum]+128)&mask) );
	    }
	    hKey += ((short)h1Key[byteNum]+128) & mask;
	    --pos;
	    mask >>= 1;
	    if (mask > 0x80 ) {
	      // go to next byte
	      ++byteNum;
	      mask = 0x80;
	      --pos;
	    }
	  }
	  if ( DEBUG ) {
	    System.out.println( "no Bits: " + d_r );
	    System.out.print( key + " -> " );
	    for ( int i=0; i< h1Key.length; ++i ) {
	      System.out.print( h1Key[i] + " " );
	    }
	    System.out.println( " -> " + hKey );
	  }
	  // make sure our key is not too large
	  hKey = hKey % d_hashTable.length;
	  return hKey;
	}
      };
    hfa.frequency( words );
    
    try {
      int noHBuckets = 1;
      do {
	int[][] histograms = hfa.histograms( noHBuckets );  
	hfa.printHistogram( histograms );
	System.out.println();
	noHBuckets = readNumber( "Number of buckets to print (-1 to quit)? ");
      } while ( noHBuckets > 0 );
    } catch ( java.io.IOException ioE ) {
      System.err.println(ioE + "Invalid number of buckets");
    }
    return;
  }
}
