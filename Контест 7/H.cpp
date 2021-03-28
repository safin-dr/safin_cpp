#include <iostream>
#include <vector>
using namespace std;

int main () {
int i, n, j, min_d, x;
vector <int> a;
cin >> n;
for (i=0;i<n;++i) {
        cin >> x;
        a.push_back(x);
        }
min_d = 2147483647;
for (i=0;i<n;++i) {
    if (a[i]<0){
        for (j=1;j<n-i;++j) {
                if (a[i+j] == -a[i]){
                    if (j < min_d) min_d = j;
                    break;}}
    }
}
if (min_d < 2147483647) cout << min_d;
else cout << 0;
return 0;}
