(*CSI3120 Assignment 4 Question 1
Trung Do 6701991
Calculate the areas of two shapes and apply an operator to them*)

datatype shape = square | rectangle | triangle | circle;

fun first (a, _, _, _) = a;
fun second (_, a, _, _) = a;
fun third (_, _, a, _) = a;
fun fourth (_, _, _, a) = a;

(*Assume that the two arguments for the triangle are the base and height
Which also means that the third number is never used for all shapes, but anyway...*)

fun area myList = if first(myList) = square then second(myList) * second(myList)
                  else if first(myList) = rectangle then second(myList) * third(myList)
                  else if first(myList) = triangle then second(myList) * third(myList) / 2.0
                  else if first(myList) = circle then second(myList) * second(myList) * 3.14
                  else 0.0;

fun processAreas operation myList = operation(area(hd myList), area(hd (tl myList)));