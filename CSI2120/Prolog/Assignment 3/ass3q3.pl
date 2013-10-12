choice(i0,a). choice(i0,b). choice(i0,c).
choice(i1,a). choice(i1,b). choice(i1,c).
choice(i2,a). choice(i2,b). choice(i2,c).

choice(j0,a). choice(j0,b). choice(j0,c).
choice(j1,a). choice(j1,b). choice(j1,c).
choice(j2,a). choice(j2,b). choice(j2,c).

choice(k0,a). choice(k0,b). choice(k0,c).
choice(k1,a). choice(k1,b). choice(k1,c).
choice(k2,a). choice(k2,b). choice(k2,c).

%find a solution
latin([[I0,I1,I2], [J0,J1,J2], [K0,K1,K2]]) :- choice(i0,I0), choice(i1,I1), choice(i2,I2), not(I0=I1), not(I1=I2), not(I2=I0),
												choice(j0,J0), choice(j1,J1), choice(j2,J2), not(J0=J1), not(J1=J2), not(J2=J0),
												choice(k0,K0), choice(k1,K1), choice(k2,K2), not(K0=K1), not(K1=K2), not(K2=K0),
												not(I0=J0), not(J0=K0), not(K0=I0),
												not(I1=J1), not(J1=K1), not(K1=I1),
												not(I2=J2), not(J2=K2), not(K2=I2).

%print out a Latin square
printLatin :- latin([[I0,I1,I2], [J0,J1,J2], [K0,K1,K2]]),
				print(I0), print(I1), print(I2), nl,
				print(J0), print(J1), print(J2), nl,
				print(K0), print(K1), print(K2).

%check if input is a latin square
isLatinSquare([[I0,I1,I2], [J0,J1,J2], [K0,K1,K2]]) :- not(I0=I1), not(I1=I2), not(I2=I0),
														not(J0=J1), not(J1=J2), not(J2=J0),
														not(K0=K1),	not(K1=K2),	not(K2=K0),
														not(I0=J0),	not(J0=K0),	not(K0=I0),
														not(I1=J1),	not(J1=K1),	not(K1=I1),
														not(I2=J2),	not(J2=K2),	not(K2=I2),
														(I0=J1;I0=J2;I0=K1;I0=K2), (I1=J0;I1=J2;I1=K0;I1=K2), (I2=J0;I2=J1;I2=K0;I2=K1),
														(J0=I1;J0=I2;J0=K1;J0=K2), (J1=I0;J1=I2;J1=K0;J1=K2), (J2=I0;J2=I1;J2=K0;J2=K1),
														(K0=I1;K0=I2;K0=J1;K0=J2), (K1=I0;K1=I2;K1=J0;K1=J2), (K2=I0;K2=I1;K2=J0;K2=J1),!.

% sample query:
% a, Find all 3x3 latin square solution
% ?- latin([[I0,I1,I2], [J0,J1,J2], [K0,K1,K2]]).
%
% b, Print all 3x3 latin square solution
% ?- printLatin.
%
% c, Check if input list is a latin square
% ?- isLatinSquare([[a,b,c], [b,c,a], [c,a,b]]).