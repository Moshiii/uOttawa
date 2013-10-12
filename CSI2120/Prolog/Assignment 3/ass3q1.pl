%Problem 1
%Database

%New York in January: team(newyork, islanders), team(montreal, team3)
%Won In Toronto: islanders, senators

team(newyork, islanders).
team(newyork, team2).
team(toronto, mapleleaf).
team(ottawa, senator).
team(montreal, team3).

match(islanders, 3, mapleleaf, 2, toronto, date(12, 2, 2013,19,45)).
match(senator, 3, newyork, 2, ottawa, date(12, 1, 2013,20,25)).
match(islanders, 3, mapleleaf, 2, newyork, date(4, 5, 2013,13,35)).
match(team3, 3, islanders, 2, newyork, date(1, 1, 2013,8,25)).
match(islanders, 2, senator, 2, toronto, date(12, 2, 2013,5,15)).
match(team3, 2, senator, 3, toronto, date(12, 2, 2013,17,25)).



%query
%a,

?- setof(team(City, Name), (team(City, Name), (match(Name,_,_,_,newyork,date(_,1,_,_,_)); match(_,_,Name,_,newyork,date(_,1,_,_,_)))), L).

%b,

?- setof(Name, (team(_, Name), ((match(Name,X,_,Y,toronto,_),X>Y);(match(_,X,Name,Y,toronto,_),X<Y))), L).