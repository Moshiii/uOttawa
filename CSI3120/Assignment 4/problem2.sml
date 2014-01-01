(*CSI3120 Assignment 4 Question 2
Trung Do 6701991
Check a guess in the Mastermind game*)

datatype color = blue | green | yellow | black | orange | pink;

datatype response = red | white | empty;

fun firstPos [a, b, c, d]  x = if a = x then red
                               else if (b = x orelse c = x orelse d = x) then white
                               else empty;

fun secondPos [a, b, c, d]  x = if b = x then red
                               else if (a = x orelse c = x orelse d = x) then white
                               else empty;

fun thirdPos [a, b, c, d]  x = if c = x then red
                               else if (a = x orelse b = x orelse d = x) then white
                               else empty;

fun lastPos [a, b, c, d]  x = if d = x then red
                               else if (a = x orelse b = x orelse c = x) then white
                               else empty;

fun diagnoseMM [[a, b, c, d], [e, f, g, h]] = [firstPos [a, b, c, d] e, 
                                               secondPos [a, b, c, d] f, 
                                               thirdPos [a, b, c, d] g, 
                                               lastPos [a, b, c, d] h ];