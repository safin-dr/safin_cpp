#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void InsertionSort(int *arr, int size) // сортировка вставками
{
    for (int curr = 0; curr < size; curr++) {
        int min = curr;
        for (int i = curr; i < size; i++) {
            if (arr[i] < arr[min]) {
                min = i;
            }
        }
        int temp;
        temp = arr[curr];
        arr[curr] = arr[min];
        arr[min] = temp;
    }
}


int main(int argc, char* argv[])
{
    std::mt19937 engine(13); // 13 - произвольное число
    std::uniform_int_distribution<int> int_dist(0, 10000);

    std::ofstream fout;

    fout.open("sorts.txt");
    for (int size = 500; size < 10001; size += 500) {
        int *arr;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = int_dist(engine);
        }
        fout << size << '\t';
        auto start = std::chrono::high_resolution_clock::now();
        InsertionSort(arr, size);
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        fout << nsec.count() << std::endl;
        delete []arr;
    }
    return 0;
}

