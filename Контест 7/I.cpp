#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector <int> ch, nech;
    int x, i, j, saver;
    while (cin >> x) {
        if (x%2 == 0) ch.push_back(x);
        if (x%2 > 0) nech.push_back(x);
    }
    for(int i = 1; i < ch.size(); i++)
    {
        for(int j = 0; j < ch.size() - 1; j++)
        {
            if(ch[j] > ch[j + 1])
            {
                saver = ch[j];
                ch[j] = ch[j + 1];
                ch[j + 1] = saver;
            }
        }
    }
    for(int i = 1; i < nech.size(); i++)
    {
        for(int j = 0; j < nech.size() - 1; j++)
        {
            if(nech[j] > nech[j + 1])
            {
                saver = nech[j];
                nech[j] = nech[j + 1];
                nech[j + 1] = saver;
            }
        }
    }
    for (i=0;i<ch.size();i++) cout << ch[i] << " ";
    for (i=0;i<nech.size();i++) cout << nech[i] << " ";
return 0;}
