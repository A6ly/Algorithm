#include <iostream>

using namespace std;

int N, d, k, c, cnt, result, arr[30000], sushi[3001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++)
	{
		if (++sushi[arr[i]] == 1)
		{
			cnt++;
		}
	}

	if (++sushi[c] == 1)
	{
		cnt++;
	}

	int l = 0, r = k - 1;

	while (l < N)
	{
		if (--sushi[arr[l++]] == 0)
		{
			cnt--;
		}

		r = (r + 1) % N;

		if (++sushi[arr[r]] == 1)
		{
			cnt++;
		}

		result = max(result, cnt);
	}

	cout << result;

	return 0;
}