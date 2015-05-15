/*
Problem 5 - Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

Notes:

	1) find all prime numbers under 20
	2) if the prime number is low enough to have a multiple of itself lower than 20, 
	   then replace the prime number with the multiple
	3) multiply all numbers
*/

#include <stdio.h>

int isprime(int i )
{
	int j;
	for (j = 2;j<i;j++)
		if (i%j==0)return 0;
	return i;	
}

int main(void) {
	
	int answer;
	int multipleofprimes = 1;
	int i;
	
	for(i = 20; i >= 2; i--)
	{
		int temp = 1;
		int h = isprime(i); 
		if(h)
		{
			printf("%d is a prime.\n", h);
				while(temp<20)
				{
					temp*=h;
				}
				multipleofprimes*=temp/h;
		}
	}
	
	printf("%d", multipleofprimes);
	
	return 0;
}
