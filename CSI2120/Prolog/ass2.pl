%1
%fact database
flight('CA101', montreal, chicoutimi, [15,30], [16,15]).
flight('CA102', chicoutimi, sherbrooke, [17,10], [17,50]).
flight('AC108', vancouver, toronto, [7,00], [14,25]).
flight('AC8988', ottawa, montreal, [19,40], [20,23]).
flight('AC431', montreal, toronto, [22,30], [23,53]).
flight('AC8713', quebecCity, vancouver, [12,20], [13,14]).
flight('AC342', quebecCity, philadelphia, [13,00], [14,34]).
flight('AC172', vancouver, halifax, [13,10], [18,52]).
flight('AC1234', calgary, vancouver, [18,15], [23,50]).

%convert the [Hour, Minute] format to minutes
timeInMinutes([Hour, Minute], X) :- X1 is Hour*60, X is X1 + Minute.

%get the duration in minutes
duration(From, To, Time) :- flight(_, From, To, Departure, Arrival),
							timeInMinutes(Departure, TimeFrom),
							timeInMinutes(Arrival, TimeTo),
							Time is TimeTo-TimeFrom.

%2

flightServesMeal(From,To) :- 	flight(_, From, To, Departure, _),
								(
									(timeInMinutes(Departure, DepartureInMinutes), DepartureInMinutes<600, duration(From, To, Time), Time>60);%10:00 is 600 minutes
									(timeInMinutes(Departure, DepartureInMinutes), DepartureInMinutes>=720, DepartureInMinutes=<810, duration(From,To, Time), Time>120);%12:00 is 720, 13:30 is 810
									(timeInMinutes(Departure, DepartureInMinutes), DepartureInMinutes>1080, duration(From, To, Time), Time>180)%18:00 is 1080
								).

%3
local_maximum([X,Y,Z], Y) :- Y>X, Y>Z, !.

% if N1 is local maximum, cut, add N1 to the result and recurse
local_maximum([N0,N1,N2|T], [N1|R]) :- local_maximum([N0, N1, N2], N1), !, local_maximum([N1,N2|T], R).
% for any other case where the list has at least three members, cut and recurse
local_maximum([_,N1,N2|T], R) :- !, local_maximum([N1,N2|T], R).
% this is reached if the list has less that three members - we're done
local_maximum(_, []).