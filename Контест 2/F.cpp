#include <iostream>

using namespace std;

int main() {
    int n, max = 0;
    int i = 0;
    cin >> n;
    while (n != 0) {
        if (n > max) {
            max = n;
            i = 0;
        } if (n == max) {
            i = i + 1;
        } cin >> n;
    } cout << i;
    return 0;
}