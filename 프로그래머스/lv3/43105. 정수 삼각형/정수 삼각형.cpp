#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
	int answer = 0;
	int dp[501][501] = { 0, };

	dp[0][0] = triangle[0][0];

	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}

	answer = *max_element(dp[triangle.size() - 1], dp[triangle.size() - 1] + triangle.size());

	return answer;
}