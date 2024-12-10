// Project Three_McNeill.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Danielle McNeill Project Three    CS-210  12-7-24  

#include "ItemTracking.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//constructor for Groceries class

Groceries::Groceries() {}

//open file and load data into vector
void Groceries::loadDataFromFile(const string& filename) {
	//check if file is open
	ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		cerr << "Error opening " << filename << endl;
		return;
	}

	string item;

	//clear out previous data
	itemNames.clear();
	itemFrequencies.clear();

	//reads the items from the file
	while (getline(inputFile, item)) {
		if (!item.empty()) {
			addItem(item); //process and add each item
		}
	}
	inputFile.close(); //close the file
}

//add item to vector and increment item tracking amount if it exists
void Groceries::addItem(const string& item) {
	//find name in itemNames vector list
	for (int i = 0; i < itemNames.size(); ++i) {
	if (itemNames[i] == item) {
		itemFrequencies[i]++;
	}
}

	//if item is not in vector list already, add it to the list
	itemNames.push_back(item);
	itemFrequencies.push_back(1);
}

//save data from vectors to frequency file
void Groceries::saveDataToFile(const string& filename) const {
	ofstream outputFile(filename);
	//check if file is open
	if (!outputFile.is_open()) {
		cerr << "Error opening " << filename << endl;
		return;
	}
	
	//writes items and frequency of item to frequency file
	for (int i = 0; i < itemNames.size(); i++) {
		outputFile << itemNames[i] << " " << itemFrequencies[i] << endl;
	}
	outputFile.close(); //Closes the file
}

//get frequency of specific item
int Groceries::getItemFrequency(const string& item) const {
	//find item in itemNames vector list
	for (int i = 0; i < itemNames.size(); ++i) {
		if (itemNames[i] == item) {
			return itemFrequencies[i];
	}
}
return 0; //if item is not on list return 0
}

// Prints the frequency of all items
void Groceries::printItemFrequency() const {
	for (int i = 0; i < itemNames.size(); ++i) {
		cout << itemNames[i] << " " << itemFrequencies[i] << endl;
	}
}

//print frequency of all items
void Groceries::printHistogram() const {
	for (int i = 0; i < itemNames.size(); i++) {
		cout << itemNames[i] << " ";
		for (int j = 0; j < itemFrequencies[i]; ++j) {
			cout << "#";
		}
		cout << endl;
	}
}
//display menu options to user
void Groceries::displayMenu() const {
	cout << "--------------------------------------------------------" << endl;
	cout << "Menu Options:\n";
	cout << "1. Search for an item\n";
	cout << "2. Print frequencies for all items\n";
	cout << "3. Print all items and frequencies\n";
	cout << "4. Exit program\n";
	cout << "Enter your choice: ";
}

//get user input and execute based on user choice
void Groceries::handleUserChoice(int choice) {
	switch (choice) {
	case 1: {
		string item;
		cout << "--------------------------------------------------------" << endl;
		cout << "Enter the item to search for: ";
		cin >> item;
		int frequency = getItemFrequency(item);
		cout << endl;
		cout << "Frequency of " << item << ": " << frequency << endl;
		break;
	}
        case 2:
			cout << "--------------------------------------------------------" << endl;
			printItemFrequency();
			break;

		case 3:
			cout << "--------------------------------------------------------" << endl;
			printHistogram();
			break;

		case 4:
			cout << "--------------------------------------------------------" << endl;
			cout << "Exiting program." << endl;
			break;

		default:
			cout << "--------------------------------------------------------" << endl;
			cout << "Invalid choice. Please try again." << endl;
	}
}