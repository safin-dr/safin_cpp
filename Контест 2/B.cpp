#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;
    bool mod = year % 400 == 0;
    if (year % 4 == 0 && year % 100 != 0 || mod) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}