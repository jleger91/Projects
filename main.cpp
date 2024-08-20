/*
*	Programmed By: Justin Leger
*	Date: 8/11/2024
*	Description: Grocery-Tracking Program
*/

#include <iostream> //used for input and output to console
#include "GroceryTracker.h" //get the grocery tracker class
using namespace std; //skips having to use std:: before cin and cout

//begin main()
int main() {
	//declare variables
	GroceryTracker myTracker;
	int inputMenuNumber;
	string userInput;

	//get map value
	//get map key
	//to use when getting the item name
	//cout << foodFrequency.first("Peaches");

	//0. Get Grocery Map and Vector
	myTracker.GetGroceryMap(); //stores food frequencies
	myTracker.GetGroceryVector(); //stores food names

	//start grocery tracker loop
	while (true) {
		//1. SHOW MENU
		myTracker.DisplayMenu(); //show the main menu
		inputMenuNumber = myTracker.ValidateMenuOption(); //get valid input from menu

		//functionality for menu option-1
		//here we get the frequency of the item entered for input
		if (inputMenuNumber == 1) {
			myTracker.GetValidFoodItem();
		}
		//functionality for menu option-2
		// here we print the name and freqency of each type of item
		if (inputMenuNumber == 2) {
			myTracker.GetAllItems();
		}
		//functionality for menu option-3
		// here we print a histogram of the food and their frequencies
		if (inputMenuNumber == 3) {
			myTracker.GetHistogram();
		}
		//functionality for menu option-4
		//here we simply exit the program
		if (inputMenuNumber == 4) {
			break;
		}
	}//end grocery tracker loop

	myTracker.BackupData(); //backup data before finishing program

	return 0; //end program

} //end main()