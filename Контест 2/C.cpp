#include <iostream>

using namespace std;

int main() {
    int n, k = 0;
    cin >> n;
    while (n != 0) {
        if (n % 2 == 0) {
            k = k + 1;
        } cin >> n;
    }
    cout << k;
    return 0;
}