#include <iostream>

using namespace std;

const int MAX = 250000;
int N, X, arr[MAX], sum, maxVisit, cnt = 1;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < X; i++)
	{
		sum += arr[0 + i];
	}

	maxVisit = sum;

	for (int i = X; i < N; i++)
	{
		sum += arr[i] - arr[i - X];

		if (sum > maxVisit)
		{
			maxVisit = sum;
			cnt = 1;
		}
		else if (sum == maxVisit)
		{
			cnt++;
		}
	}

	if (maxVisit == 0)
	{
		cout << "SAD";
	}
	else
	{
		cout << maxVisit << "\n" << cnt;
	}

	return 0;
}