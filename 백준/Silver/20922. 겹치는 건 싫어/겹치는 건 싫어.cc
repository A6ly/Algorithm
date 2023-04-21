#include <iostream>

using namespace std;

int N, K, l, r, result, arr[200000], cnt[100001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (l <= r && r < N)
	{
		if (cnt[arr[r]] < K)
		{
			cnt[arr[r++]]++;
			result = max(result, r - l);
		}
		else if (cnt[arr[r]] == K)
		{
			cnt[arr[l++]]--;
		}
	}

	cout << result;

	return 0;
}