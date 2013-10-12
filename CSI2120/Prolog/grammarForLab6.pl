s(X,Y) :- np(X,U), vp(U,Y).   % sentence

np(X,Y) :- det(X,U), n(U,Y).  % noun phrase

vp(X,Y) :- iv(X,Y).
vp(X,Y) :- tv(X,U), np(U,Y).  % verb phrase

det([the|Y], Y). % determiners
det([a|Y], Y).

n([giraffe|Y], Y). % noun
n([apple|Y], Y).

iv([dreams|Y], Y). % intransitive verb

tv([dreams|Y], Y). % transitive verb
tv([eats|Y], Y).
