% CSI3120 Assignment 1 Question 4
% Author: Trung Do
% A program that calculates the percentage of vowels, consonants and other characters in a given paragraph
% Example usage: ?- statistic("This is the first sentence. This is the second one.", PercentageOfVowel, PercentageOfConsonant, PercentageOfOther).

% X is a vowel if the ASCII code of X is in the vowel ASCII list
vowel(X) :- member(X, [65, 69, 73, 79, 85, 97, 101, 105, 111, 117]), !.

% X is a consonant if the ASCII code of X is in the consonant ASCII list
consonant(X) :- member(X, [66, 67, 68, 70, 71, 72, 74, 75, 76, 77, 78, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90,
						   98, 99, 100,102,103,104,106,107,108,109,110,112,113,114,115,116,118,119,120,121,122]), !.

% count the number of vowels in a string X
numVowel(X, NumberOfVowel) :- numVowel(X, 0, NumberOfVowel), !.
numVowel([], NumberOfVowel, NumberOfVowel).
numVowel([H|T], N, NumberOfVowel) :- vowel(H), N2 is N + 1, numVowel(T, N2, NumberOfVowel).
numVowel([_|T], N, NumberOfVowel) :- numVowel(T, N, NumberOfVowel).

% count the number of consonants in a string X
numConsonant(X, NumberOfConsonant) :- numConsonant(X, 0, NumberOfConsonant), !.
numConsonant([], NumberOfConsonant, NumberOfConsonant).
numConsonant([H|T], N, NumberOfConsonant) :- consonant(H), N2 is N + 1, numConsonant(T, N2, NumberOfConsonant).
numConsonant([_|T], N, NumberOfConsonant) :- numConsonant(T, N, NumberOfConsonant).

% count the number of other characters in a string X
numOther(X, NumberOfOther) :- length(X, Length), numVowel(X, NumberOfVowel), numConsonant(X, NumberOfConsonant), NumberOfOther is Length - NumberOfConsonant - NumberOfVowel.

% statistic of components in a string X
statistic(X, PercentageOfVowel, PercentageOfConsonant, PercentageOfOther) :- 
			length(X, Length), 
			numOther(X, NumberOfOther), 
			numVowel(X, NumberOfVowel), 
			numConsonant(X, NumberOfConsonant),
			PercentageOfOther is NumberOfOther / Length * 100,
			PercentageOfVowel is NumberOfVowel / Length * 100,
			PercentageOfConsonant is NumberOfConsonant / Length *100.