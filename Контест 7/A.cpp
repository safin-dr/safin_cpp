#include <iostream>
using namespace std;

int main(){
int a, b, c, d, x;
cin >> a >> b >> c >> d;
cin >> x;
if ((a + x == b)&&(c * x == d)) cout << 5;
else {if ((a + x == b)||(c * x == d)) cout << 4;
else {if (x == 1024) cout << 3;
else cout << 2;}}
return 0;}
