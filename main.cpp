#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <climits>
#include "Functions.cpp"
#include "fileLoader.cpp"

using namespace std;

int main() {
    vector<Produce> produceList;
    Produce currProduce;
    string menuChoices[4] = {"Look Up By Item", "Show Today's Sales", "Show In Histogram", "Exit Program"};
    int choice;
    bool restart = false;

    /* Passes produceList as arguments through file loader.cpp.
    File loader opens the file and add to produceList*/
    GetFromFile(produceList, currProduce);

    // Displays the menu for the first time
    cout << endl;
    cout << nCharString(5, ' ') << "Produce Tracker" << endl;
    printMenu(menuChoices, 4, 27);

    // Set exception mask for cin stream
    cin.exceptions(ios::failbit);

    bool ready = false;
    while (ready == false) {
        try {
            cout << endl << "Choose a menu option: ";
            cin >> choice;
            choice = isOption(choice);
            ready = true;
        }

        // Catches mismatch for cin
        catch (ios_base::failure& excpt) {
                cout << "\nYou must enter a number for this field: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
        }
    }
    

    // Program loop for main menu. Optioin 4 exits program 
    while (choice != 4) {
        try {
            /* Menu option 1: look up item. 
            If user input is in list, match is true and outputs item and amount sold.
            If not item match is false and item was not sold today*/
            if (choice == 1) {
                bool match = false;
                string item;
                cout << "\nType in the item name: ";
                cin >> item;
                item = makeUpper(item);

                for (int i = 0; i < produceList.size(); ++i) {
                    if (item == produceList.at(i).GetName()) {
                        cout << endl << produceList.at(i).GetName() << " " << produceList.at(i).GetAmount() << endl;
                        match = true;
                    }
                }
                if (match == false) {
                    cout << "\nSorry this item was not sold today." << endl;
                } 
                cout << endl;
                printMenu(menuChoices, 4, 27);
                cout << endl << "Choose a menu option: ";
                cin >> choice;
                choice = isOption(choice);

            }

            // Menu option 2: Prints produce sold today.
            if (choice == 2) {
                cout << nCharString(5, ' ') << "Sold Today" << endl;
                cout << nCharString(20, '-') << endl;
                for (int i = 0; i < produceList.size(); ++i) {
                    produceList.at(i).Print();
                }

                cout << endl;
                printMenu(menuChoices, 4, 27);
                cout << endl << "Choose a menu optioin: ";
                cin >> choice;
                choice = isOption(choice);
            }
            

            // Menu option 3: Prints produce sold today in Histogram format
            if (choice == 3) {
                cout << nCharString(7, ' ') << "Histogram" << endl;
                cout << nCharString(25, '-') << endl;
                for (int i = 0; i < produceList.size(); ++i) {
                    produceList.at(i).PrintHist();
                }

                cout << endl;
                printMenu(menuChoices, 4, 27);
                cout << endl << "Choose a menu option: ";
                cin >> choice;
                choice = isOption(choice);
        
            }

        }
        
        // Catches mismatch for cin
        catch (ios_base::failure& excpt) {
                cout << "\nYou must enter a number for this field. " << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Selecting Option 2:" << endl;
                cout << endl;
                choice = 2;
        }

    }
    // Exits the program
    cout << "Goodbye!" << endl;

    return 0;
}