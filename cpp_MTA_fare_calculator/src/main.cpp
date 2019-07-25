#include <iostream>
#include <vector>

//
std::vector<double> fares = {2.75, 32.00, 121.00};
std::vector<std::string> fare_opts = {"Pay per ride", "1 week unlimited", "30 day unlimited"};
std::vector<double> cost_per_ride(int days, int rides) {
	//cost per ride
	double ppr_price = 2.75;
	// unlimited 1 week 
	double unlimited7d_price = (days / 7) * 32.00;
	if ( days % 7 > 0) 
	{unlimited7d_price += 32.00;}
	unlimited7d_price /= rides;
	//unlimted 30 day 
	double unlimited30d_price = 121.00/rides;
	std::vector<double> ride_prices = {
	ppr_price,
	unlimited7d_price,
	unlimited30d_price
	};
	return ride_prices;
}
////
void get_best_fare(int days, int rides) 
{
	std::vector<double> ride_prices = cost_per_ride(days, rides);
	double smallest = ride_prices[0];
	int smallst_index = 0;
	for (int i = 0; i < ride_prices.size(); i++) {
		if( ride_prices[i] < smallest) {
			smallest = ride_prices[i];
			smallst_index = i;
		}	
	}
	std::cout << " the cheapest fare for you is the " << fare_opts[smallst_index] << "\n";
	std::cout << "The cost per ride is $" << smallest << "\n";
}
///
int main() 
{		
	int days, rides;
	std::cout << " \n \n Welcome to the MTA Fare Calculator \n";
		
	std::cout << "How many days will you use your metro card? \n";
	std::cin >> days;

	std::cout << "How often are you expecting to use the subway? \n";
	std::cin >> rides;
	get_best_fare(days, rides);
}