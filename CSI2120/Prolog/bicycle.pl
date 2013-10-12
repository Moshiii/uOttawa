:- set_prolog_flag(toplevel_print_options, [quoted(true), portray(true), attributes(portray), max_depth(100)]).

basicpart(rim).
basicpart(spoke).
basicpart(rearframe).
basicpart(handlebars).
basicpart(gears).
basicpart(bolt).
basicpart(nut).
basicpart(fork).

assembly(bike,[wheel,wheel,frame]).
assembly(wheel,[spoke,rim,hub]).
assembly(frame,[rearframe,frontframe]).
assembly(frontframe,[fork,handlebars]).
assembly(hub,[gears,axle]).
assembly(axle,[bolt,nut]).

partsof(X,[X]) :- basicpart(X).
partsof(X,P) :-
  assembly(X,Subparts),
  partsoflist(Subparts,P).

partsoflist([],[]).
partsoflist([P|Tail], Total) :-
  partsof(P,HeadParts),
  partsoflist(Tail,TailParts),
  append(HeadParts,TailParts,Total).

?- partsof(handlebars,Parts).
?- partsof(hub,Parts).
?- partsof(bike,Parts).
