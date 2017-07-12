#include<iostream>
using namespace std;

int main()
{

	// maximum = 1000
	unsigned short int size;
	// input the number of people
	while (scanf("%hd", &size), size)
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

		
		if (tranc_decimals >= 1)
		{
			int diff_int = tranc_decimals;
			exchange_cost += float(diff_int)/float(100);
		
		}

		printf("%.2f\n", exchange_cost);
	}

	return 0;
}
