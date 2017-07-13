#include<iostream>
#include<math.h>
using namespace std;

int main()
{

	// maximum = 1000
	unsigned short int size;
	// input the number of people
	while (scanf("%hu", &size), size)
	{
		// Create array which can contain costs
		// max cost is $10000.00
		// use integer type so that it store the input value *100 since we need to care up to 1 cent
		// it makes easier not to deal with decimals
		int costs[size];
		int sum = 0;

		// input the cost n times, and store in array	
		// calculate sum at the same time
		for (int i = 0; i < size; i++)	
		{
			// Treat cost as inters to avoid decimal rounding confusion
			int dollar;
			int cent;
			scanf("%d.%d", &dollar, &cent);
			costs[i] = dollar*100 + cent;
			sum += costs[i];
		}

		// get average cost
		// use double to have more accurate decimals
		// ex: .200000000000001 .19999999999.....
		// refer: https://stackoverflow.com/questions/33983827/choosing-between-float-and-double
		double average_cost = (double)sum / (double)size;

		// needs to be float since it store with original formant dollar.cents
		double positive = 0.0, negative = 0.0;

		for (int i = 0; i < size; i++)
		{
			// want to ignore the .decimals so change to int
			int difference = costs[i] - average_cost;
			if (difference >= 0)
				positive += difference / 100.0;
			else
				negative += -(difference) / 100.0;
		}

		// needs to be examine 
		if (positive > negative)
			printf("$%.2f\n", positive);
		else
			printf("$%.2f\n", negative);
	}
	return 0;
}
