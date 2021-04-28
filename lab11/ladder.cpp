#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> steps(n + 1);
	steps[0] = 0;
	for (int i = 1; i < n + 1; i++) 
		cin >> steps[i];

	vector<int> cur_sum(n + 1, 0);

	vector<int> root(n + 1, 0);

	cur_sum[0] = 0;
	cur_sum[1] = steps[1];

	for (int j = 2; j < n + 1; j++) 
	{
		if (cur_sum[j - 2] > cur_sum[j - 1])
		{
			cur_sum[j] = steps[j] + cur_sum[j - 2];
			root[j] = j - 2;
		}
		else
		{
			cur_sum[j] = steps[j] + cur_sum[j - 1];
			root[j] = j - 1;
		}
	}

	cout << cur_sum[n] << endl;

	vector<int> sol;
	sol.push_back(n);
	int num = n;

	while (num > 1)
	{
		sol.push_back(root[num]);
		num = root[num];
	}

	for (int i = 0; i < sol.size(); i++)
		cout << sol[sol.size() - i] << ' ';

	return 0;
}