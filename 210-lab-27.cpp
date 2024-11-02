#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

int menu();

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagers;
    int choice = 0;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagers["Audie"] = make_tuple(10, "Armadillo", "Let's climb together!");
    villagers["Raymond"] = make_tuple(3, "Cat", "I don't need any humans.");
    villagers.insert({"Marshal", make_tuple(7, "Frog", "I want that fly!")});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto& pair : villagers) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << " ";
        cout << endl;
    }


    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagers.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagers.find(searchKey);
    if (it != villagers.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagers.size() << endl;
    villagers.clear();
    cout << "Size after clear: " << villagers.size() << endl;

    while(choice !=6) {
        choice = menu();
        switch(choice) {
            case 1: {
                string name;
                int level;
                string species;
                string catchphrase;
                // Add villager
                cout << "\nVillager name: ";
                cin >> name;
                cout << "\nFriendship level: ";
                cin >> level;
                cout << "\nSpecies: ";
                cin >> species;
                cout << "\nCatchphrase: ";
                getline(cin, catchphrase);

                villagers.insert({name, make_tuple(level, species, catchphrase)});

                cout << name << " added." << endl;
                break;
            }
            case 2:
                // Delete Villager
                break;
            case 3:
                // Increase Friendship
                break;
            case 4:
                // Decrease Friendship
            case 5:
                // Search for villager
        }
    }
    return 0;
}

int menu() {
    int user_choice = 0;
    cout << "1. Add Villager" << endl;
    cout << "2. Delete Villager" << endl;
    cout << "3. Increase Friendship" << endl;
    cout << "4. Decrease Friendship" << endl;
    cout << "5. Search for Villager" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter choice: ";

    while(!(cin>>user_choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Enter a number 1-6: ";
    }

    return user_choice;
}