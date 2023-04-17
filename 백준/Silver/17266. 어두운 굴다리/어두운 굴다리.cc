#include <iostream>

using namespace std;

int N, M, arr[100000];

int BinarySearch()
{
	int left = 0, right = N;

	while (left <= right)
	{
		bool isCorrect = true;

		int mid = (left + right) / 2;

		if (arr[0] > mid || N - arr[M - 1] > mid)
		{
			isCorrect = false;
		}
		else
		{
			for (int i = 0; i < M - 1; i++)
			{
				if (arr[i + 1] - arr[i] > mid * 2)
				{
					isCorrect = false;

					break;
				}
			}
		}

		if (isCorrect)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return left;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}

	cout << BinarySearch();

	return 0;
}