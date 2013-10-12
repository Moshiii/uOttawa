%return the length of a list
list_length([],0).
list_length([_|L],N) :- list_length(L,N1), N is N1 + 1.

%return the number of direct subtree of a tree
numberOfSubtree(node(_,F), N) :- list_length(F,N).

%rules for nodes
nodes([],_,[]).

nodes([X|Xs], Y, L) :- nodes(X, Y, L1), nodes(Xs, Y, L2), append(L1, L2, L).

nodes(node(X,[]),Y,[X]) :- numberOfSubtree(node(X,[]), Y), !.
nodes(node(X,[]),Y,[]) :- numberOfSubtree(node(X,[]), Z), Z=\=Y, !.

nodes(node(X,[XT|XT2]),Y,[X|Xs]) :- numberOfSubtree(node(X,[XT|XT2]), Y), !, nodes(XT, Y, Xs1), nodes(XT2, Y, Xs2), append(Xs1,Xs2,Xs).
nodes(node(X,[XT|XT2]),Y,L) :- numberOfSubtree(node(X,[XT|XT2]), Z), Z=\=Y, !, nodes(XT, Y, L1), nodes(XT2, Y, L2), append(L1, L2, L).