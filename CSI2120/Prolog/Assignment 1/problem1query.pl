%a)	All meals suitable for a vegetarian
?- appetizer(X, Y, none), mainDish(A,B,none), dessert(M, N).

%b)	All meals with fish (As an appetizer or main dish, but not both)
?- appetizer(X, Y, Z), mainDish(A,B,C), dessert(M, N), (Z=fish;C=fish), not(Z=C).

%c)	All meals with fish or meat in the main dish.
?- appetizer(X, Y, Z), mainDish(A,B,C), dessert(M, N), (C=meat;C=fish).

%d)	All meals with main dish cheaper than 30$.
?- appetizer(X, Y, Z), mainDish(A,B,C), dessert(M, N), (B<30).