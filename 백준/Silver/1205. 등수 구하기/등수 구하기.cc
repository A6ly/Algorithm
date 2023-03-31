#include <iostream>

using namespace std;

int N, newScore, P, arr[50];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> newScore >> P;

	if (N == 0)
	{
		cout << 1;

		return 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (N == P && arr[N - 1] >= newScore)
	{
		cout << -1;

		return 0;
	}

	for (int i = 0; i < P; i++)
	{
		if (arr[i] <= newScore)
		{
			cout << i + 1;

			return 0;
		}
	}

	return 0;
}