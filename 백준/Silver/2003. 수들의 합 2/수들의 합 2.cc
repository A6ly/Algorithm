#include <iostream>

using namespace std;

int N, M, index, sum, cnt, arr[10000];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (index < N)
	{
		for (int i = index; i < N; i++)
		{
			sum += arr[i];

			if (sum == M)
			{
				cnt++;

				break;
			}
			else if (sum > M)
			{
				break;
			}
		}

		sum = 0;
		index++;
	}

	cout << cnt;

	return 0;
}