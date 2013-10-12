#Lab 7
###Hashing Functions

In this laboratory, you will be able to explore the distribution of hashed keys in a hash table. The class `HashFunctionAnalysis` creates a hash table of a specified size and it counts how many keys will hash to each index for a specific data-set. The behaviour of the hash function can be analyzed by printing a histogram of the distrubtion of the hashed keys in the table. The keys in this example are strings and hash functions can be tested on any text stored as a textfile.

Study and run the code in the `TestHashFunc.java`. You will have to provide the filename of a textfile at the command prompt. The implemented hash function is very simple: It takes the first 8 bytes of the ASCII code of each word as the key and truncates it from the left after `ceil(log(N))` bits. It interpretes these bits than as the integer index for the hash table. If you test the code with "alphabet.txt" with a hash table size of 256, you can notice that each key maps to a different index.

*Please implement a better hashing function.*

Notice how the abstract class `HashFunctionAnalysis` needs to be extended defining the abstract method `int hashFunction( String word )`. Notice also that defining `TestHashFunc.DEBUG` as `true` or `false` will create more or less verbose output, respectively.