// Danielle McNeill Project Three    CS-210  12-7-24 

#include "ItemTracking.h"
#include <iostream>

using namespace std;

int main() {
	Groceries groceries;

	//load data from project txt file
	groceries.loadDataFromFile("CS210_Project_Three_Input_File.txt");

	//Save the data to new file frequency.txt
	groceries.saveDataToFile("frequency.txt");

	//initalize start to 0
	int choice = 0;

	while (choice != 4) {
		//display my 4 menu options from Item Tracking
		groceries.displayMenu();

		//CHALLENGE: validate user input
		while (!(cin >> choice)) {
			cin.clear(); //clear error
			cin.ignore(10000, '\n'); //ignore invalid input given
			cout << "Invalid input. Please try again by entering a number between 1 and 4." << endl;
		}
		//user choice
		groceries.handleUserChoice(choice);
	}
	return 0; //exit
}