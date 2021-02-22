#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <numeric>
#include <functional>

struct Saper
{
    int columns;
    int strings;
    int** matrix;
    int** bomb_map;

    Saper(int columns, int strings)
    {
        this->columns = columns;
        this->strings = strings;
    }

    void generate_matrix()
    {
        int** matrix;

        matrix = new int* [this->strings];

        for (int i = 0; i < this->strings; i++)
        {
            matrix[i] = new int[this->columns];
        }

        for (int i = 0; i < this->strings; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                matrix[i][j] = 0;
            }
        }

        this->matrix = matrix;
    }

    void show_map()
    {
        for (int i = 0; i < this->strings; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                std::cout << this->bomb_map[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    void plant_bomb(int y, int x)
    {
        this->matrix[y - 1][x - 1] = 1;
    }

    void generate_map()
    {
        int** bomb_map;

        bomb_map = new int* [this->strings];

        for (int i = 0; i < this->strings; i++)
        {
            bomb_map[i] = new int[this->columns];
        }


        for (int i = 0; i < this->strings; i++)
        {
            for (int j = 0; j < this->columns; j++)
            {
                int value = 0;
                if (this->matrix[i][j] != 1)
                {

                    if (j + 1 < this->columns) {
                        if (this->matrix[i][j + 1] == 1) { value += 1; }
                    }
                    if (j - 1 >= 0) {
                        if (this->matrix[i][j - 1] == 1) { value += 1; }
                    }

                    if (i - 1 >= 0 && j + 1 < this->columns) {
                        if (this->matrix[i - 1][j + 1] == 1) { value += 1; }
                    }

                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if (this->matrix[i - 1][j - 1] == 1) { value += 1; }
                    }

                    if (i - 1 >= 0) {
                        if (this->matrix[i - 1][j] == 1) { value += 1; }
                    }

                    if (i + 1 < this->strings && j + 1 < this->columns) {
                        if (this->matrix[i + 1][j + 1] == 1) { value += 1; }
                    }

                    if (i + 1 < this->strings && j - 1 >= 0) {
                        if (this->matrix[i + 1][j - 1] == 1) { value += 1; }
                    }

                    if (i + 1 < this->strings) {
                        if (this->matrix[i + 1][j] == 1) { value += 1; }
                    }
                }
                else
                {
                    value = -1;
                }
                bomb_map[i][j] = value;
            }
        }

        this->bomb_map = bomb_map;
    }

    ~Saper() {
        for (int i = 0; i < this->strings; i++)
        {
            delete[] this->matrix[i];
            delete[] this->bomb_map[i];
        }
        delete[] this->matrix;
        delete[] this->bomb_map;
    }

};


int main()
{
    int columns, strings;

    std::cin >> strings >> columns;

    Saper saper = Saper(columns, strings);
    saper.generate_matrix();

    int k;
    std::cin >> k;

    for (int i = 0; i < k; i++)
    {
        int y, x;
        std::cin >> y >> x;
        saper.plant_bomb(y, x);
    }

    saper.generate_map();
    saper.show_map();

    return 0;