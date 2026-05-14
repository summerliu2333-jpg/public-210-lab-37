//COMSC-210-5068， Lab 37, Yang Liu
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(string code) {
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

    string code;
    long long grandTotal = 0;

    while (inFile >> code) {
        grandTotal += sum_ascii(code);
    }

    cout << "Total: " << grandTotal << endl;

    return 0;
}
