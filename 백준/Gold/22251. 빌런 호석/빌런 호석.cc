#include <iostream>

using namespace std;

int N, K, P, X, num[10] = { 0b1110111, 0b0010001, 0b0111110, 0b0111011, 0b1011001, 0b1101011, 0b1101111, 0b0110001, 0b1111111, 0b1111011 }, arr[10][10], result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> P >> X;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			int temp = num[i] ^ num[j];

			while (temp != 0)
			{
				if (temp & 1)
				{
					arr[i][j]++;
				}

				temp >>= 1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (i == X)
		{
			continue;
		}

		int cnt = 0, from = X, to = i;

		for (int j = 0; j < K; j++)
		{
			cnt += arr[from % 10][to % 10];
			from /= 10;
			to /= 10;
		}

		if (cnt <= P)
		{
			result++;
		}
	}

	cout << result;

	return 0;
}