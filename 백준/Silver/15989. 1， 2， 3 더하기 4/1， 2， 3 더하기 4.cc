#include <iostream>

using namespace std;

const int MAX = 10001;
int T, n, dp[MAX][4];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;

	for (int i = 4; i < MAX; i++)
	{
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	cin >> T;

	while (T--)
	{
		cin >> n;

		cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
	}

	return 0;
}