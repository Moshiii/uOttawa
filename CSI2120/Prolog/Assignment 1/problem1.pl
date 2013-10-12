%appetizer definition
%appetizer (X, Y, Z). : X is an appetizer with price Y and of type Z
%with Z being meat, fish or none
appetizer(gardenSalad, 8.5, none).
appetizer(carpaccio, 9.5, fish).
appetizer(caesarSalad, 9.5, meat).%pancetta: meat
appetizer(tomatoSalad, 9.5, none).
appetizer(mediterraneanSalad, 9.5, none).
appetizer(warmDuck, 11.95, meat).%duck: meat
appetizer(tatakiSalmon, 12.95, fish).
appetizer(antipasto, 13.95, meat).% prosciutto: ham/meat
appetizer(scallopCeviche, 13.95, meat).%scallop is meat
appetizer(sanDanielle, 11.95, meat).% prosciutto: ham/meat
appetizer(agnolotti, 11.95, none).
appetizer(cannelloni, 11.95, meat).%veal:meat
appetizer(shrimpSauteed, 13.95, meat).%shrimp:meat
appetizer(pistachioSalmon, 13.95, fish).
appetizer(strudelBromeLake, 13.95, meat).

%mainDish definition
%mainDish (X, Y, Z). : X is a main dish with price Y and of type Z
%with Z being meat, fish or none
mainDish(duoScallop, 28.95, fish).%both meat and fish???
mainDish(walleyeFillet, 28.95, fish).%walleye: fish
mainDish(roastedFillet, 28.95, fish).%trout: fish
mainDish(salmonStuffedCrab, 28.95, fish).%salmon: fish, crab: also fish
mainDish(tilapiaFillet, 29.95, fish).%tilapia: fish
mainDish(chickenBoneless, 29.95, meat).
mainDish(chickenPotato, 29.95, meat).
mainDish(consGrilledFillet, 37.75, meat).%meat
mainDish(vealMedallion, 42.95, meat).
mainDish(porkTenderloin, 30.95, meat).
mainDish(portobelloStuffed, 29.00, none).%portobello: mushroom
mainDish(quinoaRisotto, 29.00, none).
mainDish(grilledElephant, 29.00, none).%??
mainDish(tianRisotto, 29.00, none).

%dessert definition
%dessert (X, Y). : X is a dessert with price Y
dessert(creamCake, 9.25).
dessert(cheesecake, 9.25).
dessert(exoticFrozen, 9.25).
dessert(millefeuille, 9.25).
dessert(cheeseMousse, 9.25).
dessert(freshFruit, 9.25).
dessert(sugarPie, 9.25).
dessert(mapleSyrup, 9.25).
dessert(streuselPie, 9.25).
dessert(mapleSyrupTart, 9.25).
dessert(streuselPieRhubarb, 9.25).
dessert(tarteTatin, 9.25).