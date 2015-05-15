/*
Problem 3 - Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <stdio.h>
#include <math.h>

int main(void) {
	double bignumber = 600851475143 ;
	double divisor = 2; 
	
	while(divisor<bignumber)
	{
		while(fmod(bignumber,divisor)==0)//if we  find a factor, we remove it 
										 //by dividing the intial number by the factor
		{
			bignumber/=divisor;
		}
		divisor++;
	}
	printf("%f",bignumber); //outputs 6857, the divisor equals what's left over of the intial #
	return 0;
}
