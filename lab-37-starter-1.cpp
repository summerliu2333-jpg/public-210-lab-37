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

    return 0;
}
