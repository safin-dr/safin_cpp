#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

void InsertionSort(int *arr, int size) // ñîðòèðîâêà âñòàâêàìè
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
    std::mt19937 engine(13); // 13 - ïðîèçâîëüíîå ÷èñëî
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
        InsertionSort(arr[], size);
        auto end = chrono::high_resolution_clock::now();
        auto nsec = end - start;
        fout << nsec.count() << std::endl;
        delete []arr;
    }
    fout.close();
    return 0;
}

