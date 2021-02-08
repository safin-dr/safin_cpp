#include <iostream>

using namespace std;

int main() {
    int n, max = 0;
    cin >> n;
    while (n != 0) {
        if (n > max && n % 2 == 0) {
            max = n;
        } cin >> n;
    } cout << max;
    return 0;
}