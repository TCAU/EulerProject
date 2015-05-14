/*
Problem 1 - Multiples of 3 and 5

Published on Friday, 5th October 2001, 06:00 pm; Solved by 375658

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.


Answer: 233168

Code (C version C11):
*/

#include <stdio.h>

int main(void) 
{
	int count = 0;
	int i;
	
	for (i = 1; i< 1000; i++)
	{
		if( ( i % 3 == 0) || ( i % 5 == 0) )count+=i;
	}
	
	printf("%d",count); // outputs 233168
	return 0;
}