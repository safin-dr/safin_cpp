#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getNumber(int x, int num) {
	return (int) (x / pow(10, num)) % 10;
}

void print(vector<vector<int>> table) {
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < table[i].size(); j++)
			cout << table[i][j] << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> a;
	int temp;

	while (cin >> temp)
		a.push_back(temp);

	vector<vector<int>> table(2);

	for (size_t i = 0; i < a.size(); i++)
	{
		if (getNumber(a[i], 0) == 0)
			table[0].push_back(a[i]);
		else
			table[1].push_back(a[i]);
	}
	print(table);
	int num = 0;
	while (!table[1].empty())
	{
		bool f = false;
		num++;
		vector<vector<int>> temp(2);
		for (size_t i = 0; i < 2; i++)
		{
			for (size_t j = 0; j < table[i].size(); j++)
			{
				if (getNumber(table[i][j], num) == 0)
					temp[0].push_back(table[i][j]);
				else
					temp[1].push_back(table[i][j]);
				if (table[i][j] >= pow(10, num))
					f = true;
			}
		}
		table = temp;
		if (!f)
			continue;
		print(table);
	}

	return 0;
}
