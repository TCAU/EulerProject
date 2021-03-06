/*
Problem 2 - Even Fibonacci numbers

Published on Friday, 19th October 2001, 06:00 pm; Solved by 310542

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

*/

#include <stdio.h>
#include <math.h>

int main(void) {
	double count = 0;

	double fibonacci_value = 1;
	double previous_value1 = 0;
	double previous_value2 = 0;
	
	void fibonacci()
		{
			previous_value2 = previous_value1; 
			previous_value1 = fibonacci_value;
			fibonacci_value = previous_value1 + previous_value2; 			
		}
		
	while(fibonacci_value<=4000000)
	{
		fibonacci();
		if ( fmod ( fibonacci_value , 2 )==0 )
			{
				count+=fibonacci_value;
			}
	}
		
	printf("%f", count); //outputs 4613732.000000
	
	return 0;
}
