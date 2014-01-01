// CSI3120 Assignment 1 Question 1
// Author: Trung Do
// A program that calculates the percentage of vowels, consonants and other characters in a given paragraph

#include <stdio.h>

int main(void) {
	char p[100];

	int vowel=0, consonant=0, other=0, i, length;
	double percentVowel, percentConsonant, percentOther;

	printf("Enter a paragraph: \n");
	gets(p);
	printf("You entered: %s\n", p);

	length = strlen(p);
	printf("The length is: %d\n", length);


	for (i=0; i<strlen(p); i++){
		if (p[i]=='a'||p[i]=='A'||p[i]=='i'||p[i]=='I'||p[i]=='u'||p[i]=='U'||p[i]=='e'||p[i]=='E'||p[i]=='o'||p[i]=='O') vowel++;
		else if (p[i]=='b'||p[i]=='B'||p[i]=='c'||p[i]=='C'||p[i]=='d'||p[i]=='D'||p[i]=='f'||p[i]=='F'||p[i]=='g'||p[i]=='G'
				||p[i]=='h'||p[i]=='H'||p[i]=='j'||p[i]=='J'||p[i]=='k'||p[i]=='K'||p[i]=='l'||p[i]=='L'||p[i]=='p'||p[i]=='P'
				||p[i]=='q'||p[i]=='Q'||p[i]=='r'||p[i]=='R'||p[i]=='s'||p[i]=='S'||p[i]=='t'||p[i]=='T'||p[i]=='v'||p[i]=='V'
				||p[i]=='w'||p[i]=='W'||p[i]=='x'||p[i]=='X'||p[i]=='m'||p[i]=='M'||p[i]=='n'||p[i]=='N'||p[i]=='y'||p[i]=='Y'||p[i]=='z'||p[i]=='Z') consonant++;
		else other++;
	}
	printf("\nNumber of vowel: %d\n", vowel);
	printf("Number of consonant: %d\n", consonant);
	printf("Number of other characters: %d\n", other);

	percentVowel = (double)vowel/length*100;
	percentConsonant = (double)consonant/length*100;
	percentOther = (double)other/length*100;

	printf("\nPercentage of vowel: %f\n", percentVowel);
	printf("Percentage of consonant: %f\n", percentConsonant);
	printf("Percentage of other characters: %f\n", percentOther);
	
	system("pause");
	return 0;
}
