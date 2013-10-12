%kingFromTo(X, Y, Z): X is king from year Y to year Z
kingFromTo(a, 10, 80).
kingFromTo(c, 81, 100).

%kingAt(X, Y): X is king during year Y
kingAt(X, Y) :- kingFromTo(X, A, B), Y>=A, Y=<B.

grandfather(X, Y) :- father(X, Z), father(Z, Y).

%father(X, Y): X is the father of Y
father(a, b).
father(a, c).
father(c, d).
father(c, e).

born(a, 1).
born(b, 20).
born(c, 18).
born(d, 38).
born(e, 40).

died(a, 80).
died(b, 90).
died(c, 70).
died(d, 100).
died(e, 98).

male(a).
male(b).
male(c).
male(d).
male(e).

%get the eldest son of a father
eldestSon(EldestSon, Father) 	:- 	father(Father, EldestSon), born(EldestSon, SmallestBornYear), 
   								\+ (father(Father, AnotherSon), born(AnotherSon, SmallerBornYear), SmallerBornYear < SmallestBornYear).

%get the eldest eldest grandchild of a grandfather
eldestGrandchild(EldestGrandchild, Grandfather)	:-	grandfather(Grandfather, EldestGrandchild),	born(EldestGrandchild, SmallestBornYear),
												\+	(grandfather(Grandfather, AnotherGrandchild), born(AnotherGrandchild, SmallerBornYear),
													SmallerBornYear<SmallestBornYear).

%X is the successor to the throne in year Year 
successor(X, Year) :- (kingAt(King, Year), eldestSon(X, King), male(X)) ; (kingAt(King, Year), eldestGrandchild(King, X), male(X)).