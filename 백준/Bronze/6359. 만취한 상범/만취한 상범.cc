#include <iostream>

using namespace std;

int T, n, cnt;
bool arr[101];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;

		cnt = 0;
		fill_n(arr, 101, false);

		for (int j = 2; j <= n; j++)
		{
			for (int k = j; k <= n; k += j)
			{
				arr[k] = !arr[k];
			}
		}

		for (int j = 1; j <= n; j++)
		{
			if (!arr[j])
			{
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}