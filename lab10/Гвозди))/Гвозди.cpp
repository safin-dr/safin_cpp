#include <iostream>
#include <vector>

using std::vector;
using std::min;
using std::cin;
using std::cout;

void bubble_sort(vector <int> arr) 
{
    for (int j = 0; j < arr.size() - 1; j++) 
    {
        for (int i = 0; i < arr.size() - 1; i++) 
        {
            int tmp;
            if (arr[i + 1] < arr[i]) 
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    vector <int> nails(N + 2, 0); 
    vector <int> table(N + 2, 0); 

    for (int i = 0; i < N; i++)
        cin >> nails[i];

    nails[N] = 0;
    nails[N + 1] = 0;

    bubble_sort(nails); 

    for (int i = N - 1; i >= 0; i--)
        table[i] = min(table[i + 1], table[i + 2]) + abs(nails[i] - nails[i + 1]);

    cout << table[0];

    return 0;
}