#include<iostream>
#include<math.h>
using namespace std;

int main()
{

	// maximum = 1000
	unsigned short int size;
	int counter = 0;
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
			/* 9.44 become 943.99 after multiplying by 100.0
			 * examine later
			float temp;
			// 9.44 become 943 in this way
			scanf("%f", &temp); // don't forget &
			temp *= 100;	
			printf("temp is %f\n", temp);
			costs[i] = temp * 100; // .00 * 100 make num integer
			printf("before %d\n : ", costs[i]);
			sum += costs[i];
			*/
			int dollar;
			int cent;
			scanf("%d.%d", &dollar, &cent);
			costs[i] = dollar*100 + cent;
			sum += costs[i];
		}

		// get average cost
		// don't forget change size to float
		float average_cost = (float)sum / (float)size;

		// needs to be float since it store with original formant dollar.cents
		float positive = 0.0, negative = 0.0;

		for (int i = 0; i < size; i++)
		{
			// want to ignore the .decimals so change to int
			float difference = costs[i] - average_cost;
			if (difference >= 0)
				positive += ((int)difference) / 100.0;
			else
				negative += -1.0*(((int)difference) / 100.0);
		}

		// explain why later
		if (positive > negative)
			printf("$%.2f\n", positive);
		else
			printf("$%.2f\n", negative);
	}

	return 0;
}
