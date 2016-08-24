#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Items.h"
using namespace std;

int main()
{
	vector <Items> store; // vector of the objects of type Items.
	Items item; // create an object of items.
	ifstream file; 
	file.open("StoreData.txt");// opens the text file.


	while (file) // statement to get data from the object, then creates a new object in the vector.  This will go on until all data is inputted.
	{
		file >> item.id >> item.itemName1 >> item.itemName2 >> item.pOrdered >> item.pInStore >> item.pSold >> item.manufPrice >> item.sellingPrice;
		store.push_back(item);
	}

	char done = 'n';

	while (done != 'y') // program will run until user wants to exit.
	{
		char choice;
		cout << "What would you like to do?: " << endl; // menu driven program.
		cout << "1. Check for Item in Store. " << endl;
		cout << "2. Sell an item. " << endl;
		cout << "3. Print Report. " << endl;

		cin >> choice;

		if (choice == '1')
		{
			char choice;
			cout << "Search by a. Name or b. ID? ('a' / 'b'): "; // user is given the choice to search by name or item id. 
			cin >> choice;
			cout << endl;

			if (choice == 'a') // user chooses name
			{
				string firstname, lastname;
				cout << "Enter Item Name: ";
				cin >> firstname >> lastname; // user enters item name.

				bool found = false;
				for (int i = 0; i < store.size() - 1; i++)
				{
					if (firstname == store[i].itemName1 && lastname == store[i].itemName2)
					{
						if (store[i].pInStore > 0) // if the item inventory is greater than zero, found = true
							found = true;
					}
				}
				if (found == true)
					cout << "Yes, the item is in stock. " << endl; // item is in stock.
				else
					cout << "The item is not available in store. " << endl;

			}

			if (choice == 'b') // user wants to search via item id
			{
				int inputid;

				cout << "Input Item ID: "; // user inputs id.
				cin >> inputid;
				cout << endl;

				bool found = false;
				for (int i = 0; i < store.size() - 1; i++)
				{
					if (inputid == store[i].id )
					{
						if (store[i].pInStore > 0)
							found = true; // if item has a greater inventory than zero, item is in stock.
					}
				}
				if (found == true)
					cout << "Yes, the item is in stock. " << endl;
				else
					cout << "The item is not available in store. " << endl;
			}
		}

		if (choice == '2') // user wants to sell an item.
		{
			char choice;
			cout << "Search by a. Name or b. ID? ('a' / 'b'): "; // search by name or id.
			cin >> choice;
			cout << endl;

			if (choice == 'a')
			{
				string inputstring1, inputstring2; 
				cout << "Enter Item Name: "; 
				cin >> inputstring1 >> inputstring2; // input item name.
				cout << endl;

				for (int i = 0; i < store.size() - 1; i++)
				{
					if (inputstring1 == store[i].itemName1  && inputstring2 == store[i].itemName2)
					{
						store[i].pInStore = store[i].pInStore - 1; // deincrements in-store inventory by 1.
						store[i].pSold = store[i].pSold + 1; // increments number of item sold by 1.
					}
					else
						continue;

				}


			}

			if (choice == 'b')
			{
				int input;
				cout << "Enter ID: ";
				cin >> input; // user searches by id.

				for (int i = 0; i < store.size() - 1; i++)
				{
					if (input == store[i].id)
					{
						store[i].pInStore = store[i].pInStore - 1; // deincrements item in store by 1. 
						store[i].pSold = store[i].pSold + 1;  // increments items sold by 1.
					}
					else
						continue;

				}
			}
		}

		if (choice == '3')
		{
			string a[100];
			for (int i = 0; i < store.size() - 1; i++)
			{
				a[i] = store[i].itemName1;
			}

			Items temp;
			int iteration, index;

			int length = store.size() - 1;
			for (iteration = 1; iteration < length; iteration++)
			{
				for (index = 0; index < length - iteration; index++)
				{
					if (store[index].itemName1 > store[index+1].itemName1) // bubble sort to sort the names of items before printing.
					{
						temp = store[index];
						store[index] = store[index + 1]; // the objects of the vector are sorted based on the names.
						store[index + 1] = temp;
					}
				}
				
			}
			cout << "itemID    " << "Item Name     " << "pOrdered   " << "pInstore    " << "pSold  " << "manufPrice " << "sellingPrice" << endl;

			for (int i = 0; i < store.size() - 1; i++)
			{
				store[i].print(); // calls upon the print function of the sorted vector.
			}

			double totalprice = 0;
			for (int i = 0; i < store.size() - 1; i++)
			{
				totalprice = totalprice + (store[i].pInStore * store[i].sellingPrice); // total price is calculated based on the inventory and value of the inventory.
			}

			cout << "Total Inventory: $" << totalprice << endl;

			double totalcount = 0;
			for (int i = 0; i < store.size() - 1; i++)
			{
				totalcount = totalcount + store[i].pInStore; // total count is added up based on items in store.
			}
			cout << "Total Items in the Store: " << totalcount << endl;
		}

		cout << "Are you done ('y' / 'n')? "; // user chooses if they'd like to continue or not.
		cin >> done;
	}
	file.close(); // file is closed.
}

