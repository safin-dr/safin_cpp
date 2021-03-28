#include <iostream>
using namespace std;

int main () {
    int n, i, j;
int** a = new int*[1000];
for (int i = 0; i < 1000; ++i){
    a[i] = new int[1000];
}
int** b = new int*[1000];
for (int i = 0; i < 1000; ++i){
    b[i] = new int[1000];
}
cin >> n;
for (i=0; i<n; ++i) for (j=0; j<n; ++j) cin >> a[i][j];
for (j=0;j<n;++j) {
    for (i=0;i<n;++i) cout << a[n-i-1][j] << " ";
    cout << endl;
}
return 0;}
