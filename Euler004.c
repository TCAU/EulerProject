/*
Problem 4 - Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 Å~ 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Notes:

	Largest number possible is 999*999 = 998001, which has 6 base ten digits.
	Smallest number possible is 100*100 = 10000, which has 5 base ten digits.
*/

#include <stdio.h>
#include <math.h>

int palindrome_test_sixdigits(int i, int j)
{
	int hundredsdigit, singledigit, bottom, mirrorbottom;
	int testvalue = i*j;
	bottom = testvalue % 1000;
	mirrorbottom = bottom;	

	singledigit = bottom % 10;
	hundredsdigit = bottom / 100;
			
	mirrorbottom +=  (singledigit - hundredsdigit) * 100; 
	
	mirrorbottom +=  (hundredsdigit - singledigit); 

	if ( mirrorbottom == (testvalue/1000) ) 
	{
		return testvalue;		
	}
	
	return 0;		
}

int main(void) {

	int threedigitvalue;
	int threedigitvalue2;
	int largest = 0;

	for ( threedigitvalue = 999 ; threedigitvalue > 99 ; --threedigitvalue )
		for ( threedigitvalue2 = 999 ;  threedigitvalue2 > 99 ; --threedigitvalue2 )
		{
			int h = palindrome_test_sixdigits(threedigitvalue, threedigitvalue2); 
			if(h)
			{
				if (largest< h)
				{
					largest = h;
				}
			}
		}

	printf("%d",largest); 
	return 0;
}

