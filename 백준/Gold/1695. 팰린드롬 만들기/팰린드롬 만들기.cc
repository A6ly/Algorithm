#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 5000;
int N, arr[MAX], dp[MAX][MAX];

int palindrome(int start, int end)
{
	if (start >= end)
	{
		return 0;
	}

	int& cnt = dp[start][end];

	if (cnt != -1)
	{
		return cnt;
	}

	cnt = 0;

	if (arr[start] == arr[end])
	{
		cnt += palindrome(start + 1, end - 1);
	}
	else
	{
		cnt += 1 + min(palindrome(start + 1, end), palindrome(start, end - 1));
	}

	return cnt;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << palindrome(0, N - 1);

	return 0;
}