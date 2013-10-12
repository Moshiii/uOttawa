import net.datastructures.PriorityQueue;
import net.datastructures.HeapPriorityQueue;

public class PQTest {

  public static void main(String[] args) {

    if (args.length > 1) {
      PriorityQueue<Integer,Integer> pq;
      pq = new HeapPriorityQueue<Integer,Integer>();
      for (int i=1;i<args.length;i++) {
	pq.insert(new Integer(Integer.parseInt(args[i])), 
		  new Integer(Integer.parseInt(args[i])));
      }
      for (int j=1;j<Integer.parseInt(args[0]);j++) {
	pq.removeMin();
      } 
      System.out.println("The " + Integer.parseInt(args[0]) + 
			 "th smallest element is " + 
			 pq.removeMin().getValue());
    }      
    else {System.out.println("Usage: java PQTest <k> <elements>");}
  }
}