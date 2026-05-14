//COMSC-210-5068， Lab 37, Yang Liu
#include <iostream>
#include <string>
using namespace std;

int sum_ascii(string code) {
    int sum = 0;

    for (char c : code) {
        sum += (int)c;
    }

    return sum;
}

int main() {
    string test = "ABC";
    cout << sum_ascii(test) << endl; //expect 198

    return 0;
}
