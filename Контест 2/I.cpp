#include <iostream>
#include <string>

using namespace std;

int main()
{
    int speed;
    cin >> speed;
    string num;
    cin >> num;
    int sum = 0;
    while (num != "A999AA")
    {
        if (speed > 60) {
            if (num[1] == num[2] && num[2] == num[3]) {
                sum += 1000;
            }
            else if (num[1] == num[2] || num[1] == num[3] || num[2] == num[3]) {
                sum += 500;
            }
            else {
                sum += 100;
            }
        }
        cin >> speed;
        cin >> num;
    }
    cout << sum;
    return 0;
}