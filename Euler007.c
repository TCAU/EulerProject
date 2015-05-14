/*
Problem 7 - 10001st prime

Published on Friday, 28th December 2001, 06:00 pm; Solved by 190085

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?

Notes:

	1) make an empty array of 10001 integers, set the first one to 2
	2) keep filling the array with primes until we reach the 10001st prime.

Answer: 104743
 
Code (C version C11):
*/

#include <stdio.h>

int isprime(int i, int primes[], int firstemptyindex)
{
	int j;
	for (j = 0; j < firstemptyindex ; j++)
		if (i%primes[j]==0)return 0;
	return i;	
}

int main(void) {

	int primes[10001];
	primes[0]=2;
	int firstemptyindex = 1;
	
	int count = 0;
	int i = 1;
	
	while(count<10000){
		i++;
		int h = isprime(i, primes, firstemptyindex); 
		if(h)
		{
			count++;
			primes[firstemptyindex]=h;
			firstemptyindex++;
		}
	}
	
	printf("%d", primes[10000]);
	
	return 0;
}
