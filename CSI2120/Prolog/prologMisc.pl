member(X, [X|_]).
member(X, [_|Y]) :- member(X,Y).

islist([A|B]) :- islist(B).
islist([]).
