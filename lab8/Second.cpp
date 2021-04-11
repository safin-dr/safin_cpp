#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void SelectionSort(int arr[], int n) //сортировка выбором
{
     for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i;
        while (j > 0 && arr[j-1] > temp) {
            arr[j] = arr[j-1];
            j = j - 1;
        }
        arr[j] = temp;
    }
}

void main() {
    std::mt19937 engine(13); // 13 - произвольное число
    std::uniform_int_distribution<int> int_dist(0, 10000);

    std::ofstream fout;

    fout.open("sorts.txt");
    for (int size = 500; size < 10001; size += 500) {
        int *arr;
        arr = new int[size];

        for (int i = 0; i < n; i++) {
            arr[i] = int_dist(engine);
        }
        fout << size << '\t';
        auto start = chrono::high_resolution_clock::now();
        SelectionSort(arr[], size);
        auto end = chrono::high_resolution_clock::now();
        auto nsec = end - start;
        fout << nsec.count() << std::endl;
        delete []arr;
    }
    return 0;
}
