:- dynamic empl/5, dept/3.

% empl(EmployeeNumber, FamilyName, OtherNames, DepartmentNumber, Salary)

empl(e(071), 'Bloom',   'Irving', d(1), 520).
empl(e(085), 'Proulx',  'Marie',  d(1), 645).
empl(e(112), 'Johnson', 'Tony',   d(2), 540).
empl(e(115), 'Brown',   'John',   d(3), 680).
empl(e(117), 'Smith',   'Jill',   d(2), 510).
empl(e(125), 'Smith',   'John',   d(3), 495).
empl(e(203), 'Prasad',  'Anita',  d(2), 610).
empl(e(211), 'Gromov',  'Denis',  d(3), 515).

% dept(DepartmentNumber, DepartmentName)

dept(d(1), 'Checkout', e(085)).
dept(d(2), 'Mens'' Shoes', e(203)).
dept(d(3), 'Ladies'' Shoes', e(115)).

% a three-keystroke device to list the contents of the database
%listing(empl).
%listing(dept).
