#include <iostream>

using namespace std;

int N, K, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = N; i > 0; i--)
	{
		if (N % i == 0)
		{
			cnt++;

			if (cnt == K)
			{
				cout << N / i;

				break;
			}
		}
	}

	if (cnt < K)
	{
		cout << 0;
	}

	return 0;
}