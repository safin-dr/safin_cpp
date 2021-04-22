#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;

int main()
{
	int s, n;
	cin >> s;
	cin >> n;

	vector<int> coin_types(n + 1, 0);	//array of coins' nominals
	for (size_t i = 1; i < n + 1; i++)
		cin >> coin_types[i];

	vector<vector<int>> table(s + 1, vector<int>(n + 1, 0));	//table with numbers(from our lesson I know hot to full it :)))
	for (size_t i = 0; i < s + 1; i++)
		table[i][0] = s + 1;
	for (size_t i = 0; i < n + 1; i++)
		table[0][i] = 0;

	for (int j = 1; j < n + 1; j++)
	{
		for (int i = 1; i < s + 1; i++)
		{
			if (i >= coin_types[j])
			{
				if (table[i - coin_types[j]][j] + 1 < table[i][j - 1])
					table[i][j] = table[i - coin_types[j]][j] + 1;
				else
					table[i][j] = table[i][j - 1];
			}
			else
				table[i][j] = table[i][j - 1];
		}
	}

	cout << table[s][n];
	return 0;
}
