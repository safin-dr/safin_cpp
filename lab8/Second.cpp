#include "stdafx.h"
#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n) //сортировка выбором
{
    int count, key;
    for (int i = 0; i < n - 1; i++) {
        count = arr[i];
        key = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[key])
                key = j;
        if (key != i) {
            arr[i] = arr[key];
            arr[key] = count;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " "; //вывод массива
}

void main() {
    setlocale(LC_ALL, "Rus");
    int n, arr[1000];
    cin >> n;
    for ( int i = 0; i < n; i++)
        cin >> arr[i];
    SelectionSort(arr, n);
    system("pause >> void");
}
