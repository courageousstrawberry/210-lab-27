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

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villagers.begin(); 
                                               it != villagers.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

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
                while (!(cin >> level) || level < 0 || level > 10) {
                    cout << "\nInvalid friendship level. Enter an integer 0-10: ";
                }
                cout << "\nSpecies: ";
                cin >> species;
                cout << "\nCatchphrase: ";
                getline(cin, catchphrase);

                villagers.insert({name, make_tuple(level, species, catchphrase)});

                cout << name << " added." << endl;

                // Display all villagers
                cout << "Villager details:" << endl;
                for (auto& pair : villagers) {
                    cout << pair.first << " [";
                    cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]";
                    cout << endl;
                }
                break;
            }
            case 2: {
                // Delete Villager
                string name;
                cout << "Enter a villager's name to delete: ";
                cin >> name;
                villagers.erase(name);

                // Display all villagers
                cout << "Villager details:" << endl;
                for (auto& pair : villagers) {
                    cout << pair.first << " [";
                    cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]";
                    cout << endl;
                }
                break;
            }
            case 3:
                // Increase Friendship
                string name;
                cout << "Enter name of villager to decrease friendship: ";
                cin >> name;

                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int& friendship = get<0>(it->second);
                    if ((friendship + 1) <= 10){
                        friendship++;
                    }
                }
                else {
                    cout << "Villager not found!" << endl;
                }

                // Display all villagers
                cout << "Villager details:" << endl;
                for (auto& pair : villagers) {
                    cout << pair.first << " [";
                    cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]";
                    cout << endl;
                }
                break;
            case 4:
                // Decrease Friendship

                // Display all villagers
                cout << "Villager details:" << endl;
                for (auto& pair : villagers) {
                    cout << pair.first << " [";
                    cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]";
                    cout << endl;
                }
                break;
            case 5:
                // Search for villager

                // Display all villagers
                cout << "Villager details:" << endl;
                for (auto& pair : villagers) {
                    cout << pair.first << " [";
                    cout << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]";
                    cout << endl;
                }
                break;
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