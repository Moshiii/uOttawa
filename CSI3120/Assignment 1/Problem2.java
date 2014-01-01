// CSI3120 Assignment 1 Question 2
// Author: Trung Do
// A program that calculates the percentage of vowels, consonants and other characters in a given paragraph

import java.util.Scanner;


public class Problem2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String p;
		String vowelList = "aiueoAIUEO";
		String consonantList = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

		int vowel=0, consonant=0, other=0, i, length;
		double percentVowel, percentConsonant, percentOther;

		System.out.println("Enter a paragraph: \n");
		p = input.nextLine();
		System.out.println("You entered: " + p);

		length = p.length();
		System.out.println("The length is: " + length);


		for (i=0; i<p.length(); i++){
			if (vowelList.indexOf(p.charAt(i))!=-1) vowel++;
			else if (consonantList.indexOf(p.charAt(i))!=-1) consonant++;
			else other++;
		}
		System.out.println("\nNumber of vowel: " + vowel);
		System.out.println("Number of consonant: " + consonant);
		System.out.println("Number of other characters: " + other);

		percentVowel = (double)vowel/length*100;
		percentConsonant = (double)consonant/length*100;
		percentOther = (double)other/length*100;

		System.out.println("\nPercentage of vowel: " + percentVowel);
		System.out.println("Percentage of consonant: " + percentConsonant);
		System.out.println("Percentage of other characters: " + percentOther);
	}

}
