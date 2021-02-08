#include <iostream>

using namespace std;

int main() {
    int n, i = 1;
    cin >> n;
    while (0 < n) {
        if (n == 1) {
            cout << "YES";
            break;
        }
        if (n % 2 == 0) {
            n = n / 2;
        }
        else {
            cout << "NO";
            break;
        }
    } return 0;
}