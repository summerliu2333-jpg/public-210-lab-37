//COMSC-210-5068， Lab 37, Yang Liu
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string code) {
    int sum = 0;

    for (char c : code) {
        sum += (int)c;
    }

    return sum;
}

int main() {
    ifstream inFile("lab-37-data.txt");

    if (!inFile) {
        cout << "Could not open the file." << endl;
        return 1;
    }

    map<int, list<string>> hash_table;
    string code;

    while (inFile >> code) {
        int hashIndex = gen_hash_index(code);
        hash_table[hashIndex].push_back(code);
    }

    int choice;

    while (true) {
        cout << "---- MENU ----" << endl;
        cout << "1. Print first 100 entries" << endl;
        cout << "2. Search for a key" << endl;
        cout << "3. Add a key" << endl;
        cout << "4. Remove a key" << endl;
        cout << "5. Modify a key" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                int count = 0;

                for (auto entry : hash_table) {
                    cout << "Entry #" << count + 1 << endl;
                    cout << "Hash index: " << entry.first << endl;

                    cout << "Codes: ";


                    // Display only the first 10 codes in the list to keep the output from becoming too large
                    int codeCount = 0;
                    for (string value : entry.second) {
                        cout << value << " ";
                        codeCount++;

                        if (codeCount == 10) {
                            break;
                        }
                    }

                    cout << endl;
                    cout << "Total codes in the entry: " << entry.second.size() << endl;
                    cout << endl;

                    count++;

                    if (count == 100) {
                        break;
                    }
                }
            }

            case 2: {
                string searchKey;

                cout << "Enter key to search: ";
                cin >> searchKey;

                int hashIndex = gen_hash_index(searchKey);
                bool found = false;

                for (string value : hash_table[hashIndex]) {
                    if (value == searchKey) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Key found." << endl;
                    cout << "Hash index: " << hashIndex << endl;
                }

                else {
                    cout << "Key not found." << endl;
                }

                break;
            }

            case 3: {
                string newKey;

                cout << "Enter key to add: ";
                cin >> newKey;

                int hashIndex = gen_hash_index(newKey);

                hash_table[hashIndex].push_back(newKey);

                cout << "Key added." << endl;
                cout << "Inserted into hash index: " << hashIndex << endl;
                cout << "Total codes in this bucket now: "
                    << hash_table[hashIndex].size() << endl;

                break;
            }

            case 4: {
                string removeKey;

                cout << "Enter key to remove: ";
                cin >> removeKey;

                int hashIndex = gen_hash_index(removeKey);
                bool found = false;

                for (string value : hash_table[hashIndex]) {
                    if (value == removeKey) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    hash_table[hashIndex].remove(removeKey);

                    cout << "Key removed." << endl;
                    cout << "Removed from hash index: " << hashIndex << endl;
                    cout << "Total codes in this bucket now: "
                        << hash_table[hashIndex].size() << endl;
                }
                else {
                    cout << "Key not found. Nothing removed." << endl;
                }

                break;
            }

            case 5: {
                string oldKey;
                string newKey;

                cout << "Enter key to modify: ";
                cin >> oldKey;

                int oldHash = gen_hash_index(oldKey);
                bool found = false;

                for (string value : hash_table[oldHash]) {
                    if (value == oldKey) {
                        found = true;
                        break;
                    }
                }

                if (found) {
                    cout << "Enter new replacement key: ";
                    cin >> newKey;

                    hash_table[oldHash].remove(oldKey);

                    int newHash = gen_hash_index(newKey);
                    hash_table[newHash].push_back(newKey);

                    cout << "Key modified." << endl;
                    cout << "Old hash index: " << oldHash << endl;
                    cout << "New hash index: " << newHash << endl;
                }
                else {
                    cout << "Key not found. Nothing modified." << endl;
                }

                break;
            }

            case 6: {
                cout << "Exiting program." << endl;
                return 0;
            }

            default: {
                cout << "Invalid option." << endl;
                break;
            }

        }
    }

    return 0;
}