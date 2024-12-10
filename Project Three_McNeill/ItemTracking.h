// Danielle McNeill Project Three    CS-210  12-7-24 

#ifndef ITEMTRACKING_H
#define ITEMTRACKING_H

#include <vector>
#include <string>

using namespace std;

//declare groceries class for item tracking

class Groceries {
	//accessed by any class
public:
	Groceries();

	//define function voids that will not return values
    void loadDataFromFile(const string& filename);
    void saveDataToFile(const string& filename) const;
    int getItemFrequency(const string& item) const;
    void printItemFrequency() const;
    void printHistogram() const;
    void displayMenu() const;
    void handleUserChoice(int choice);
    void addItem(const string& item);

    // Can only be accessed by groceries class
private:
    vector<string> itemNames;
    vector<int> itemFrequencies;
};

#endif