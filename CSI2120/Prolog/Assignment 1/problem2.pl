%know(X, Y): X knows Y
know(michael, jack).
%friend(X, Y): X knows Y, Y knows X, X is friend of Y, Y friend of X


%a
known(X) :- know(_, X).

%b
recognize(X, Y) :- know(X, Y), know(Y, X).

%c
presenter(X, Y, Z) :- friend(X, Z), know(X, Y).

%d
triangle(X, Y, Z) :- know(X, Y), know(X, Z), friend(Y, Z).


