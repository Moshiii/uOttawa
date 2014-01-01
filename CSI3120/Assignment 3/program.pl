# CSI 3120 Assignment 3 Problem 1 and 2
# Trung Do 6701991

my %database = (
	"Camel" => {
					"fname" => "Kaka",
					"grade"  => "B+",
				},
	"Elephant" =>{
					"fname" => "Clark",
					"grade"  => "C",
				},					
	"Kangaroo" =>{
					"fname" => "Anthony",
					"grade"  => "A",
				},
	"Monkey" =>{
					"fname" => "Mark",
					"grade"  => "D+",
				},				
	"Smith" =>{
					"fname" => "Peter",
					"grade"  => "A+",
				},
	"Turtle" =>{
					"fname" => "Jack",
					"grade"  => "C",
				},	
	"Zebra" =>{
					"fname" => "Sylvia",
					"grade"  => "C",
				}
);

# Just a helper function. Don't mind the name.
# $_[0]: the input string
# $_[1]: the position of the first letter of the target words
# $_[2]: number of words in the target word
# return: a string stating the positions of the target words in the input string
sub wordPosition{
	my $sub = substr($_[0], 0, $_[1]);
	my $initialPos = scalar(split " ", $sub) + 1;
	my $spaceInWord = $_[2];
	my $tempString = "$initialPos";
	while ($spaceInWord ne 1){
		$initialPos++;
		$tempString .= ", $initialPos";
		$spaceInWord--;
	}
	return $tempString;
}

for (;;) {
	print "Please choose an operation:\n1: insert\t2: delete\t3: modify\t4: print\t5: retrieve\t6:substitute\t0: exit \n";
	$input = <STDIN>;
	chomp $input;
	if ($input eq 1){
		print "Please enter the last name of the student: ";
		$lname = <STDIN>;
		chomp $lname;
		print "Please enter the first name of the student: ";
		$fname = <STDIN>;
		chomp $fname;
		$database{$lname}->{"fname"} = $fname;
		sort keys %database;
		print "The new student was added to the database. Thank you!\n\n";
	}
	elsif ($input eq 2){
		print "Please enter the last name of the student: ";
		$lname = <STDIN>;
		chomp $lname;
		if (exists $database{$lname}){
			delete $database{$lname};
			print "Student ", $lname, " was deleted from the database, Thank you!\n\n";
		}
		else {
			print "Invalid name.\n\n"
		}
	}
	elsif ($input eq 3){
		print  "Please enter the last name of the student whose grade you wish to enter: ";
		$lname = <STDIN>;
		chomp $lname;
		if (exists $database{$lname}){
			print "Please enter the grade: ";
			$grade = <STDIN>;
			chomp $grade;
			$database{$lname}->{"grade"} = $grade;
			print "Student's record was updated, Thank you!\n\n";
		}
		else {
			print "Invalid name.\n\n"
		}
	}
	elsif ($input eq 4){
		foreach $lname (sort keys %database) {
			print $lname, ", ", $database{$lname}->{"fname"}, " --> ", $database{$lname}->{"grade"}, "\n";
		}
		print "\n";
	}
	elsif ($input eq 5){
		print  "Please enter the grade of interest: ";
		$grade = <STDIN>;
		chomp $grade;
		$flag = 0;
		foreach $lname (keys %database) {
			if ($database{$lname}->{"grade"} eq $grade){
				$flag++;
				print $lname, ", ", $database{$lname}->{"fname"}, " --> ", $database{$lname}->{"grade"}, "\n";
			}
		}
		print "No student has that grade!\n" if ($flag eq 0);
		print "\n";
	}
	elsif ($input eq 6){
		print "Please enter the paragraph: ";
		my $input = <STDIN>;
		chomp $input;
		print "\n";

		my $input2 = $input;# need to keep the original input for reference

		# Match names in the following formats:
		# Title FirstName LastName
		# Title LastName 
		# Title FirstNameInitial. LastName
		# FirstName LastName
		# FirstNameInitial. LastName
		while ($input =~ m/(((((Mr\.|Mrs\.|Ms\.|Miss)\s)([A-Z][a-z]+\s|[A-Z]\.\s)?|([A-Z][a-z]+\s|[A-Z]\.\s))([A-Z][a-z]+))|(([A-Za-z](\+|-)?)\s((S|s)tudent(s?))))/g) {
			# $& = matched text, $1 = the whole thing, $2 = the whole name part
			# $3 = Title + FirstName/Initial part
			# $4 = Title part + space, $5 = title part without space
			# $6 = firstname part, $7 = firstname standalone part
			# $8 = lastname part
			# $9 = X student part, $10 = X (the grade) part
			# $11 = the +/- part, $12 = Students part, $13 = S/s part
			# $14 = s at the end of student part

			# if a name is found
			if ($2){		
				if (exists $database{$8} && exists $database{$8}->{"grade"}){
						my $sub = $database{$8}->{"grade"};
						$input2 =~ s/$&/the $sub student, $&/g;
				}
				else {
					print "Warning: \"", $2, "\" (position ", wordPosition($input, $-[0], scalar(split " ", $2)) ,") did not match any student in the database\n";
				}
			}

			# if "X Student" is found
			elsif ($9){
				my $counter = 0;
				my $tempString = "";

				# check how many students have this grade
				foreach $lname (keys %database) {
					if ($database{$lname}->{"grade"} eq $10){
						$counter++;
					}
				}

				# if there's at least one student who has this grade
				if ($counter>0){

					# another counter here for recognizing the end of the name list
					# for dealing with the "and" later
					my $counter2 = 0;

					foreach $lname (keys %database) {
						if ($database{$lname}->{"grade"} eq $10){
							$tempString = $tempString.$database{$lname}->{"fname"}." ".$lname;

							# dealing with "and" at the end of the name list
							$counter2++;
							if ($counter>=2){ # need to ensure there's at least 2 students with this grade
								if ($counter2 eq $counter-1){ # if we're 1 name behind the end of the name list
									$tempString = $tempString." and ";
								}
								elsif ($counter2 ne $counter){ 
									$tempString = $tempString.", ";
								}
							}
						}
					}

					# substitute the string
					if ($counter eq 1){# if there's only one student with the grade
						if ($14){# if "students"
							print "Warning: \"", $12, "\" (position ", wordPosition($input, $-[12], 1) ,") was singularized\n";
							my $withoutS = substr($&, 0, -1);
							$input2 =~ s/\Q$&\E/$withoutS, $tempString/g;							
						}
						else {
							$input2 =~ s/\Q$&\E/$&, $tempString/g;
						}
					}
					else {# if there are multiple students with the grade
						if ($14){# if "students"
							$input2 =~ s/\Q$&\E/$&, $tempString/g;
						}
						else { # if "student"
							print "Warning: \"", $12, "\" (position ", wordPosition($input, $-[12], 1) ,") was pluralized\n";
							$input2 =~ s/\Q$&\E/$&s, $tempString/g;
						}
					}		
				}
				else {
					print "Warning: \"", $9, "\" (position ", wordPosition($input, $-[9], 2) ,") did not match any student in the database\n";
				}
			}
		}

		print "\nThe result paragraph: \n";
		print $input2, "\n\n";
	}
	elsif ($input eq 0){
		last;
	}
	else {
		print "Invalid input\n\n";
	}
}

