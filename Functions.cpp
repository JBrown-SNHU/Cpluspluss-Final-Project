#include <iostream>
#include <string>
#include <cctype>
#include "Produce.h"

using namespace std;

// Class Function

// Constructor
Produce::Produce() {
    amountSold = 1;
    itemName = "none";
}

// Set number of sold
void Produce::SetAmount(int amount) {
    amountSold = amount;

    return;
}

// Gets number sold
int Produce::GetAmount() const {
    return amountSold;
}

// Sets name of produce
void Produce::SetName(string name) {
    itemName = name;

    return;
}

// Gets name of produce
string Produce::GetName() const {
    return itemName;
}

// Prints name and amount sold of produce
void Produce::Print() {
    cout << setw(12) << left << itemName << setw(5) << right;
    cout << amountSold << endl;
}

// Prints name and amount sold in Histogram format
void Produce::PrintHist() {
    cout << setw(12) << left << itemName << setw(12) << right;
    cout << nCharString(amountSold, '*')<< endl;
}

// Other Functions 

// Functinon outputs a character a certain number of times
string nCharString(size_t n, char c) {
    string border;
    for (int i = 0; i < n; ++i) {
        border += c;
    }

    return border;
}

// Fuction displays the main menu
void printMenu(string menu[], unsigned int numStrings, unsigned char width) {

    cout << nCharString(width, '*') << endl;
    
    for (int i = 0; i < numStrings; ++i) {
        cout << "* " << (i + 1) << " - " << setw(19) << left << menu[i] << "*" << endl;
    }
    cout << nCharString(width, '*') << endl;

  return;
}

// Capitalizes the first character of a string. Used for Menu Option 1
string makeUpper(string item) {
    for (int i = 0; i < item.size(); ++i) {
        if (i == 0) {
            item.at(i) = toupper(item.at(i));
        }
    }
    return item;
}

// Catches Menu Choices input that are not in range
int isOption(int num) {
    while ((num < 1) || (num > 4)) {
        cout << "\nYour have entered an invalid choice." << endl;   
        cout << "Chooe a menu option: ";
        cin >> num;
    }

    return num;
}