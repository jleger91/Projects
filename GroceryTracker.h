#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

//includes
#include <map>
#include <vector>
#include <string>
using namespace std;

//begin class GroceryTracker
class GroceryTracker {
	public:
		//functions
		void DisplayMenu(); //will display the menu screen
		int ValidateMenuOption(); //gets valid menu input from user
		void GetValidFoodItem(); //handles menu option 1
		int GetGroceryMap(); //puts frequencies of items into a map
		void GetGroceryVector(); //puts names of items into a vector
		void GetAllItems(); //handles menu option 2
		void GetHistogram(); //handles menu option 3
		int BackupData(); //backs up data to frequency.dat
	private:
		//variables
		map<string, int> foodFrequency; //map that will contain food item frequencies
		vector<string> foodNames; //vector that will contain food item names

}; //end class GroceryTracker

#endif