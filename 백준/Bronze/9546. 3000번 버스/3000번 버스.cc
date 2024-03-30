#include <iostream>

using namespace std;

int T, k, num[31];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	num[1] = 1;

	for (int i = 2; i <= 30; i++)
	{
		num[i] = num[i - 1] * 2 + 1;
	}

	for (int i = 0; i < T; i++)
	{
		cin >> k;

		cout << num[k] << "\n";
	}

	return 0;
}