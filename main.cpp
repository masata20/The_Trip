#include<iostream>
#include<math.h>
using namespace std;

int main()
{

	// maximum = 1000
	unsigned short int size;
	float exchange_costs[1000];
	int counter = 0;
	// input the number of people
	while (scanf("%hu", &size), size)
	{
		// Create array which can contain costs
		// max cost is $10000.00
		// float is shortest decimal data type in c++
		float costs[size];
		float sum = 0.0;

		// input the cost n times, and store in array	
		// calculate sum at the same time
		for (int i = 0; i < size; i++)	
		{
			scanf("%f", &costs[i]);
			sum += costs[i];
		}

		// get average cost
		// don't forget change size to float
		float average_cost = sum / (float)size;

		float exchange_cost = 0.0;

		float tranc_decimals = 0.0;
		// calculate the diff of each with average, need to cut off after 2 decimals
		// add up the only positive diffences
		// or do only half of them iff it's sorted(maybe slower than above)
		for (int i = 0; i < size; i++)
		{
			float diff = average_cost - costs[i];
			//printf("row difference is %.5f\n", diff);
			if(diff > 0.0)
			{
				// trancate after 2 decimals
				float temp = diff * 100;
				int diff_int = temp;
				tranc_decimals += temp - diff_int;
				float trancated_diff = float(diff_int)/float(100);

				exchange_cost += trancated_diff;
			}


		}
	//	printf("rvalue is %.5f\n", exchange_cost);	

		// float rounded_up = ceilf(exchange_cost * 100) / 100; 	
		// printf("rounded_up value is %.5f\n", rounded_up);
		
		int x = exchange_cost*100;
		//cout << "x is " << x << endl;
		int deci = x%10;
		//cout << "dece is " << deci << endl;
		// Dont want to add when .09
		if (tranc_decimals >= 1 && deci != 9)
		{
		// cout << "You reading this" << endl;
			int diff_int = tranc_decimals;
			exchange_cost += float(diff_int)/float(100);
		
		}

		exchange_costs[counter] = exchange_cost;
		counter++;
	}
	for (int i = 0; i < counter; i++)
		printf("$%.2f\n", exchange_costs[i]);


	return 0;
}
