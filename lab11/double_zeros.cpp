#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int k;

	cin >> n >> k;
	vector<int> zeros(n + 1);
	vector<int> no_zeros(n + 1);

	zeros[1] = 0;
	no_zeros[1] = k - 1;
	for (int i = 2; i < n + 1; i++)
	{
		no_zeros[i] = (no_zeros[i - 1] + zeros[i - 1]) * (k - 1);
		zeros[i] = no_zeros[i - 1];
	}

	cout << no_zeros[n] + zeros[n];
	return 0;
}