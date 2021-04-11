#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void qsort(int *arr, int first, int last) {
    int x, temp;
    int i = first, j = last;
    x = arr[(i + j) / 2]; // опорный берется из середины
    do {
        while (arr[i] < x) {i++;}
        while (arr[j] > x) {j--;}
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i < j);
    if (first < j) {qsort(arr, first, j);}
    if (i < last) {qsort(arr, i, last);}
}

int main() {
    std::mt19937 engine(13); // 13 - произвольное число
    std::uniform_int_distribution<int> int_dist(0, 10000);

    std::ofstream fout;

    fout.open("sorts.txt");
    for (int size = 500; size < 10001; size += 500) {
        int *arr = new int[size];
        for (int i = 0; i < size; i++) {
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
