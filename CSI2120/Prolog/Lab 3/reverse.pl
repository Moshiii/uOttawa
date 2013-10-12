% You only have to reverse the top level of the list. The behaviour of your predicate will be as follow
% ?- myReverse([a, b, vc, d, e, f], L). 
% L = [f, e, d, vc, b, a]. 
%
% ?- myReverse([a, [b, c, [d]], 0.17, p( 23, abc), [], klm], L). 
% L = [klm, [], p(23, abc), 0.17, [b, c, [d]], a]. 

myReverse([], []).
myReverse([Elt | Elts], Reversed) :-  myReverse(Elts, ReversedElts), append(ReversedElts, [Elt], Reversed).

myReverse2(List, Reversed) :- reverseAux(List, [], Reversed).
reverseAux([], Reversed, Reversed).
reverseAux([Elt | Elts], ReversedFront, Reversed) :- reverseAux(Elts, [Elt | ReversedFront], Reversed).


% reverses a list on all levels, like this: 
% ?- reverseAll([a, [b, c], [d, [e, f], g], h], L). 
% L = [h, [g, [f, e], d], [c, b], a]. 

reverseAll(X, X) :- \+ is_list(X).
reverseAll([], []).
reverseAll([X | Xs], Y) :-  reverseAll(X, XRev), reverseAll(Xs, XsRev), append(XsRev, [XRev], Y).


% Given a pair of lists of the same length, build a list of pairs: first elements, second elements, and so on. For example:
% ?- pairs([a, b, c, d, e], [1, 2, 3, 4, 5], L). 
% L = [pair(a, 1), pair(b, 2), pair(c, 3), pair(d, 4), pair(e, 5)]. 
%
% If the lists are not of the same length, your predicate fails: 
% ?- pairs([a, b, c, d, e], [1, 2, 3, 4, 5, 6], L). 
% false.

pairs([], [], []).
pairs([Elt1 | Elts1], [Elt2 | Elts2], [pair(Elt1, Elt2) | OtherPairs]) :- pairs(Elts1, Elts2, OtherPairs).


% Given a list, select its top-level elements that are numbers, like this: 
% ?- numbersOnly([1, 2, w, 3, ee, 4, [1], r, 5], L). 
% L = [1, 2, 3, 4, 5]. 
numbersOnly([], []).
numbersOnly([N | Elts], [N | Numbers]) : number(N),  numbersOnly(Elts, Numbers).
numbersOnly([H | Elts], Numbers) :-   \+ number(H), numbersOnly(Elts, Numbers).

% Select all numbers that sit on the list
% ?- allNumbersOnly([1, 2, w, 3, ee, 4, [1], r, 5], L). 
% L = [1, 2, 3, 4, 1, 5].
allNumbersOnly([], []).
allNumbersOnly([N | Elts], [N | Numbers]) :-number(N), allNumbersOnly(Elts, Numbers).
allNumbersOnly([H | Elts], Numbers) :-  is_list(H),   allNumbersOnly(H, HNumbers),  allNumbersOnly(Elts, EltsNumbers),  append(HNumbers, EltsNumbers, Numbers).
allNumbersOnly([H | Elts], Numbers) :-  \+ is_list(H),  \+ number(H),  allNumbersOnly(Elts, Numbers).
