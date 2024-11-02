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
    villagers["Audie"] = make_tuple(10, "Armadillo", "Let's dig together!");
    villagers["Raymond"] = make_tuple(3, "Cat", "I'm sleepy.");
    villagers.insert({"Marshal", make_tuple(7, "Frog", "Eat that fly!")});

    while(choice !=6) {
        choice = menu();
        switch(choice) {
            case 1: {
                string name;
                int level;
                string species;
                string catchphrase;
                // Add villager
                cout << "Villager name: ";
                cin >> name;
                cout << "Friendship level: ";
                while (!(cin >> level) || level < 0 || level > 10) {
                    cout << "\nInvalid friendship level. Enter an integer 0-10: ";
                }
                cout << "Species: ";
                cin >> species;
                cin.ignore();
                cout << "Catchphrase: ";
                getline(cin, catchphrase);

                villagers.insert({name, make_tuple(level, species, catchphrase)});

                cout << name << " added." << endl;
                cout << endl;

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
            case 3: {
                // Increase Friendship
                string name;
                cout << "Enter name of villager to increase friendship: ";
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
            }
            case 4: {
                // Decrease Friendship
                string name;
                cout << "Enter name of villager to decrease friendship: ";
                cin >> name;

                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    int& friendship = get<0>(it->second);
                    if ((friendship - 1) >= 0){
                        friendship--;
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
            }
            case 5: {
                // Search for villager
                string name;
                cout << "Enter the name of the villager to search: ";
                cin >> name;

                auto it = villagers.find(name);
                if (it != villagers.end()) {
                    cout << "\nVillager found!" << endl;
                }
                else {
                    cout << "Villager not found." << endl;
                }

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
        cout << endl;
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

    while(!(cin>>user_choice) || user_choice > 6 || user_choice < 1) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Enter a number 1-6: ";
    }

    return user_choice;
}