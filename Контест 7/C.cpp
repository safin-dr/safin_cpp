#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main () {
double x, m_x, m_x2;
vector <double> a;
m_x = m_x2 = 0.0;
cin >> x;
while (x != 0){
a.push_back(x);
m_x += x;
m_x2 += x*x;
cin >> x;
}
m_x = m_x/a.size();
m_x2 = m_x2/a.size();
if (int(round(m_x*1000))%10 > 0) printf( "%.3f ", m_x);
else {
    if (int(round(m_x*100))%10 > 0) printf( "%.2f ", m_x);
    else printf( "%.1f ", m_x);
}
if (int(round((m_x2-m_x*m_x)*1000))%10 > 0) printf( "%.3f ", (m_x2-m_x*m_x));
else {
    if (int(round((m_x2-m_x*m_x)*100))%10 > 0) printf( "%.2f ", (m_x2-m_x*m_x));
    else printf( "%.1f ", (m_x2-m_x*m_x));
}
return 0;}
