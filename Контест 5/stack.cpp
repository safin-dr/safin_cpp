#include <iostream>
#include <stack>
#include <math.h>

int read() {
    int x;
    std::cin >> x;
    return x;
}

int main() {
    std::stack<int> s;
    int x;
    while((x = read()) != 0){
        if (x > 0)
            s.push(x);
        else if (not s.empty()) {
            if (abs(x) < s.top())
                s.top() += x;
            else
                s.pop();
        }
    }
    if (s.empty())
        std::cout << 0 << ' ' << -1;
    else
        std::cout << s.size() << ' ' << s.top();
}