/*
Problem 9 - Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

Notes: A cap of 1000 combined value of a + b + c makes the answer easy to brute force
*/

#include <stdio.h>

int main(void) {

	int answer = 1;
	int c;
	int b;
	int a;
	
	for (c = 3; c <= 997; c++)
		for(b = 2; b < c ; b++)
			for(a = 1 ; a < b ; a++)
		{
			if (  ( (a*a)+(b*b) == (c*c) ) && (a+b+c==1000) ) 
			{
				answer = a*b*c;
				goto printanswer; // goto is bad for bigger programs, but fine here
			}
		}

	printanswer:	
	printf("answer is %d",answer);

	return 0;
}
