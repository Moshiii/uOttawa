%kingFromTo(X, Y, Z): X is king from year Y to year Z
kingFromTo(henry, 844, 878).
kingFromTo(richard, 878, 916).
kingFromTo(alexander, 916, 950).

%kingAt(X, Y): X is king during year Y
kingAt(X, Y) :- kingFromTo(X, A, B), Y>=A, Y=<B.

grandfather(X, Y) :- father(X, Z), father(Z, Y).

%father(X, Y): X is the father of Y
father(henry, richard).
father(richard, alexander).
father(richard, doe).

born(richard, 830).%richard born in 830
born(alexander, 860).%alexander born in 860
born(doe, 865).

died(richard, 920).%and died in 920
died(alexander, 955).%and died in 955
died(doe, 940).

male(richard).
male(alexander).
male(doe).

%get the eldest son of a father
eldestSon(EldestSon, Father) 	:- 	father(Father, EldestSon), born(EldestSon, SmallestBornYear), 
   								\+ (father(Father, AnotherSon), born(AnotherSon, SmallerBornYear), SmallerBornYear < SmallestBornYear).

%get the eldest eldest grandchild of a grandfather
eldestGrandchild(EldestGrandchild, Grandfather)	:-	grandfather(Grandfather, EldestGrandchild),	born(EldestGrandchild, SmallestBornYear),
												\+	(grandfather(Grandfather, AnotherGrandchild), born(AnotherGrandchild, SmallerBornYear),
													SmallerBornYear<SmallestBornYear).

%X is the successor to the throne in year Year 
successor(X, Year) :- (kingAt(King, Year), eldestSon(X, King), male(X)) ; (kingAt(King, Year), eldestGrandchild(King, X), male(X)).