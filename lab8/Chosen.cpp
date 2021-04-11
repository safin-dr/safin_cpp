#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void Merge(int *arr, int first, int last) {
    int mid, start, final;
    int *new_arr = new int[100];
    mid = (first + last) / 2;
    start = first;
    final = mid + 1;

    for (int j = first; j <= last; j++)
        if ((start <= mid) && ((final > last) || (arr[start] < arr[final]))) {
            new_arr[j] = arr[i];
            start++;
            }
        else {
            new_arr[j] = arr[final];
            final++;
        }

  for (int j = first; j <= last; j++)
    arr[j] = new_arr[j];
  delete[] new_arr;
};

void MergeSort(int *arr, int first, int last) {
    if (first < last) {
        MergeSort(arr, first, (first + last) / 2);
        MergeSort(arr, (first + last) / 2 + 1, last);
        Merge(arr, first, last);
    }
}

void main() {
    std::mt19937 engine(13); // 13 - произвольное число
    std::uniform_int_distribution<int> int_dist(0, 10000);

    std::ofstream fout;

    fout.open("sorts.txt");
    for (int size = 500; size < 10001; size += 500) {
        int *arr = new int[size];
        for (int i = 0; i < size++) {
            arr[i] = int_dist(engine);
        }
        fout << size <<  '\t';
        auto start = std::chrono::high_resolution_clock::now();
            qsort(arr, 0, size - 1);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        fout << nsec.count() << std::endl;
        delete []arr;
    }
    return 0;
}
