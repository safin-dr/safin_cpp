#include <iostream>
#include <vector>

using std::cin;
using std::vector;
using std::cout;

int main()
{
	int w, n;
	cin >> w;
	cin	>> n;
	vector<vector<int>> table(w + 1, vector<int>(n + 1, 0));

	vector<int> price(n + 1, 0);
	vector<int> weight(n + 1, 0);

	for (int i = 1; i < n + 1; i++)
		cin >> price[i];

	for (int i = 1; i < n + 1; i++)
		cin >> weight[i];

	for (int i = 1; i < w + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if ((i - weight[j]) >= 0)
			{
				if (table[i - weight[j]][j - 1] + price[j] > table[i][j - 1])
					table[i][j] = table[i - weight[j]][j - 1] + price[j];

				else
					table[i][j] = table[i][j - 1];
			}
			else
				table[i][j] = table[i][j - 1];
		}
	}

	cout << table[w][n];
	return 0;
}