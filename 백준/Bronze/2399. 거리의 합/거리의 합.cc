#include <iostream>

using namespace std;

int n;
long long arr[10000], result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			result += abs(arr[i] - arr[j]);
		}

		for (int j = i - 1; j > -1; j--)
		{
			result += abs(arr[i] - arr[j]);
		}
	}

	cout << result;

	return 0;
}