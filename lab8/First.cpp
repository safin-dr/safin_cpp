#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>

int main()
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
        int temp;

        // Сортировка массива пузырьком
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto nsec = end - start;
        fout << nsec.count() << std::endl;
        delete []arr;
    }
    return 0;
}
