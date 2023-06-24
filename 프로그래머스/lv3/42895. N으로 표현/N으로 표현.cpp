#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int number)
{
	int answer = -1;

	if (N == number)
	{
		return 1;
	}

	vector<vector<int>> dp(9, vector<int>());
	string str = to_string(N);

	for (int i = 1; i <= 8; i++)
	{
		dp[i].push_back(stoi(str));
		str += to_string(N);
	}

	for (int i = 2; i <= 8; i++)
	{
		for (int j = 1; j < i; j++)
		{
			for (int k = 0; k < dp[j].size(); k++)
			{
				for (int l = 0; l < dp[i - j].size(); l++)
				{
					dp[i].push_back(dp[j][k] + dp[i - j][l]);
					dp[i].push_back(dp[j][k] - dp[i - j][l]);
					dp[i].push_back(dp[j][k] * dp[i - j][l]);

					if (dp[i - j][l] != 0)
					{
						dp[i].push_back(dp[j][k] / dp[i - j][l]);
					}
				}
			}
		}

		if (find(dp[i].begin(), dp[i].end(), number) != dp[i].end())
		{
			answer = i;

			break;
		}
	}

	return answer;
}