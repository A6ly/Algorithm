#include <iostream>

using namespace std;

int H, W, arr[500], result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> H >> W;

	for (int i = 0; i < W; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < W - 1; i++)
	{
		int l = 0, r = 0;

		for (int j = i - 1; j >= 0; j--)
		{
			l = max(l, arr[j]);
		}

		for (int j = i + 1; j < W; j++)
		{
			r = max(r, arr[j]);
		}

		result += max(0, min(l, r) - arr[i]);
	}

	cout << result;

	return 0;
}