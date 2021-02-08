#include <iostream>
#include <string>

using namespace std;

int main()
{
    string ans;
    string not_ans;
    int num;
    cin >> num;
    while (num != 0) {
        not_ans = "";
        int r;
        r = num % 60;
        for (int i = 0; i < r % 10; i++) {
            not_ans += "v";
        }
        for (int i = 0; i < r / 10; i++) {
            not_ans += "<";
        }
        num = num / 60;
        if (num != 0) {
            not_ans += ".";
        }
        ans += not_ans;
    }
    int len;
    len = ans.length();
    for (int i = 0; i < len; i++) {
        cout << ans[len - i - 1];
    }
    return 0;
}