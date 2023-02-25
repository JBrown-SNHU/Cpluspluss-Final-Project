#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Produce.h"

using namespace std;

void GetFromFile(vector<Produce>& produceList, Produce& currProduce) {
    ifstream importFile;
    ofstream outputFile;
    string fileName = "CS210_Project_Three_Input_File.txt";
    char item[15];
    

    /*From here to line 90 the code runs automatically
    without user interference*/

    // Opens file set to fileName
    importFile.open(fileName);
    
    // Checks if file is open
    if (! importFile.is_open()) {
        cout << "Could not open your file!" << endl;
        return;
    }

    /* Checks for the end of file. If not, */
    int i = 0;
    int sameItem;
    while (! importFile.eof()) {
        importFile >> item;
        sameItem = 0;

        // Adds the first item on the file to the produceList
        if ((! importFile.fail()) && (i == 0)) {
            currProduce.SetName(item);
            produceList.push_back(currProduce);
        }

        /* If not the first item, for loop determines if there are duplicates
        of the item in the produceList. If there are then the count of the time will be 
        updated and the item will not be added to the list. If there are no duplicates the
        item will be added to produceList.*/  
        if ((! importFile.fail()) && (i != 0)) {
            for (int j = 0; j < produceList.size(); ++j) {
                if (item == produceList.at(j).GetName()) {
                    produceList.at(j).SetAmount(produceList.at(j).GetAmount() + 1);
                    sameItem += 1;
                }
            }

            if ((sameItem == 0) && (i != 0)) {
                currProduce.SetName(item);
                produceList.push_back(currProduce);
            }
        }
        ++i;
    }


    // Closes the file when done
    importFile.close();

    // Opens the file to write to
    outputFile.open("frequency.dat");

    // Checks that the file is open
    if (! outputFile.is_open()) {
        cout << "Could not open your file!" << endl;
    }

    /* For loop runs throught the length of the vector.
    prints produce and the amount purchased to the file */
    for (int i = 0; i < produceList.size(); ++i) {
        outputFile << produceList.at(i).GetName() << " " << produceList.at(i).GetAmount() << endl;
    }

    // Closes the file when done.
    outputFile.close();
    // End of automatic code.

    return;
}