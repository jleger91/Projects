//begin includes
#include <iostream> //allows input and output to console
#include <limits> //allows skipping of bad input
#include <fstream> //allows reading and writing of files
#include <algorithm> //allows toupper()
#include <iomanip> //allows modification of the printed messages
#include "GroceryTracker.h" //get the grocery tracker class
//end includes
using namespace std; //skips having to use std:: before cin and cout


//begin DisplayMenu()	will display the menu screen
void GroceryTracker::DisplayMenu() {
	cout << "Welcome to the Grocery Tracker Program" << endl;
	cout << "Please enter a number to select one of the following options" << endl;
	//MENU OPTION 1: Find frequency by item name
	cout << "\n1. Find Frequency by Item Name" << endl;
	//MENU OPTION 2: Print whole shopping list
	cout << "2. Print Full List" << endl;
	//MENU OPTION 3: Print list as histogram
	cout << "3. Print List as Histogram" << endl;
	//MENU OPTION 4: Exit program
	cout << "4. Exit program" << endl;

} //end DisplayMenu()


//begin ValidateMenuOption()	will get valid menu input from user
int GroceryTracker::ValidateMenuOption() {
	int userInput;

	//validation loop
	while (true) {
		cin >> userInput; //get input

		//tests that input is a number
		if(!cin) {
			cin.clear(); //reset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip the input
			cout << "Invalid input; try again" << endl;
			continue;
		}//end number test

		//tests that input is in range
		if (userInput < 1 || userInput > 4) {
			cout << "Input is out of range" << endl;
			continue;
		}//end input range test

		//input is a number and is in range
		else {
			break; //escape validation loop
		}//end else
	}//end vlidation loop

	cout << "\033[2J\033[1;1H"; //clear screen after valid input is entered
	return userInput;

} //end ValidateMenuOption()


//begin GetValidFoodItem()	will handle menu option 1
void GroceryTracker::GetValidFoodItem() {
	string userInput;

	cout << "Please enter a food item to look up" << endl;

	//begin item get loop
	while (true) {
		cin >> userInput; //get input
		//make the first letter uppercase
		userInput[0] = char(toupper(userInput[0]));

		//if item is found on the list
		if (foodFrequency.count(userInput) == 1) {
			cout << "There are: " << foodFrequency.at(userInput) << ' ' << userInput << endl;
			break; //exit loop
		}
		else {
			cout << "Item is not on the list; try again" << endl;
		}
	} //end item get loop

	//continue program
	cout << "Enter anything to continue" << endl;
	cin >> userInput;
	cout << "\033[2J\033[1;1H"; //clear screen after valid input is entered

} //end GetValidFoodItem()


//begin GetAllItems()	will handle menu option 2
void GroceryTracker::GetAllItems() {
	string userInput;

	cout << "Here is a list of all items and their frequencies\n" << endl;

	//print out all the foods
	for (const auto &food : foodNames) {
		cout << setw(12) << food << ' ' << foodFrequency.at(food) << endl;
	}

	//continue program
	cout << "\nEnter anything to continue" << endl;
	cin >> userInput;
	cout << "\033[2J\033[1;1H"; //clear screen after valid input is entered

} //end GetAllItems()


//begin GetHistogram()	will handle menu option 3
void GroceryTracker::GetHistogram() {
	string userInput;

	cout << "Here is a histogram of all items\n" << endl;

	//print out a histogram of all the foods
	for (const auto& food : foodNames) {
		cout << setw(12) << food << ' ';
		for (int i = 0; i < foodFrequency.at(food); i++) {
			cout << '*';
		}
		cout << endl;
	}

	//continue program
	cout << "\nEnter anything to continue" << endl;
	cin >> userInput;
	cout << "\033[2J\033[1;1H"; //clear screen after valid input is entered

} //end GetHistogram()


//begin GetGroceryMap()		will put all food frequencies into a map
int GroceryTracker::GetGroceryMap() {
	//gets map by looking at file and uses the map as a private data member of the class

	//declare and initialize variables
	ifstream file("CS210_Project_Three_Input_File.txt");
	string food;

	//attempt to open file
	if (file.is_open()) {
		//when file opens, read from file into map
		while (file >> food) {
			++foodFrequency[food]; //populate the map
		}
		//afterwords, close the file
		file.close();
	}
	//if file did not open
	else {
		cout << "Could not open the file" << endl;
		return 1; //1 indicates failure
	}

	return 0; //0 indicates success

} //end GetGroceryMap()


//begin GetGroceryVector()		will put all food names into a vector
void GroceryTracker::GetGroceryVector() {
	//get food names from the map and put into the vector foodNames
	for (auto iter = foodFrequency.begin(); iter != foodFrequency.end(); ++iter) {
		foodNames.push_back(iter->first);
	}
} //end GetGroceryVector()


//begin BackupData()		will backup data into frequency.dat
int GroceryTracker::BackupData() {
	//declare and initialize variables
	ofstream file("frequency.dat");
	string food;

	cout << "Generating backup data in frequency.dat" << endl;

	//attempt to open file
	if (file.is_open()) {
		for (const auto& food : foodNames) {
			file << food << ' ' << foodFrequency.at(food) << endl;
		}
		//afterwords, close the file
		file.close();
	}
	//if file did not open
	else {
		cout << "Could not open the file" << endl;
		return 1; //1 indicates failure
	}

	return 0; //0 indicates success

} //end BackupData()