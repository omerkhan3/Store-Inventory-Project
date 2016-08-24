#include <iostream>
using namespace std;

class Items // item class
{
public:  // in essence, this class will be very similar to a struct, as it will contain all public members.
	int id;
	string itemName1, itemName2;
	int pOrdered;
	int pInStore;
	int pSold;
	double manufPrice;
	double sellingPrice;

	void print() // print function for the report.
	{
		cout << id << setw(10) << itemName1 << setw(10) << itemName2 << setw(10) << pOrdered << setw(10) << pInStore << setw(10) << pSold << setw(10) << manufPrice << setw(11) << sellingPrice << endl;
	}
};
	