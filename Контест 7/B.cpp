#include <iostream>
#include <vector>
using namespace std;

int main(){
int n, x, i;
vector <int> a;
cin >> n;
for (i=0; i<n; i++) {
    cin >> x;
    if ((x%4 == 0)&&(x/1000 != 4)&&(x/1000 != 5)) a.push_back(x);
    else {if ((x%7 == 0)&&(x/1000 != 1)&&(x/1000 != 7)) a.push_back(x);
          else if ((x%9 == 0)&&(x/1000 != 9)&&(x/1000 != 8)) a.push_back(x);}
}
if (a.empty()) cout << 0;
else
    for (i=0; i<a.size(); i++) cout << a[i] << endl;
return 0;}
