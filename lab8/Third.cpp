#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void insertionSort(int *, int);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int size_array;
    cin >> size_array;

    int *sorted_array = new int [size_array];
    for (int i = 0; i < size_array; i++)
    {
        sorted_array[i] = rand() % 100; // заполняем массив случайными числами
        cout << setw(2) << sorted_array[i] << "  "; // вывод массива на экран
    }
    cout << "n";

    insertionSort(sorted_array, size_array);

    for (int i = 0; i < size_array; i++)
        cout << setw(2) << sorted_array[i] << "  "; // печать отсортированного массива

    cout << "n";
    delete [] sorted_array; // высвобождаем память
    system("pause");
    return 0;
}

void insertionSort(int *arrayPtr, int length) // сортировка вставками
{
    int temp, item;
    for (int i = 1; i < length; i++)
    {
        temp = arrayPtr[i];
        item = i - 1;
        while(item >= 0 && arrayPtr[item] > temp)
        {
            arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
            arrayPtr[item] = temp;
            item--;
        }
    }
}
