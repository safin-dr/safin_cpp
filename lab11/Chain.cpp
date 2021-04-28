#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compare(string& a, string& b) 
{
	if (a.size() > b.size())
		return false;

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
	}

	return true;
}

int main() 
{
	int n;
	cin >> n;
	vector<string> data(n);
	for (int i = 0; i < n; i++)
		cin >> data[i];

	vector<int> len(n);

	for (int i = 0; i < n; i++)
	{
		len[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (compare(data[j], data[i]))
				len[i] = max(len[i], len[j] + 1);
		}
	}

	int result = len[0];
	for (int i = 0; i < n; i++)
		result = max(result, len[i]);

	cout << result;
	return 0;
}