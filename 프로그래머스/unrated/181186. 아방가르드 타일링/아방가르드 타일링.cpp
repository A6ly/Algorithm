#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    
    long long dp[n + 2];
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 10;
    dp[4] = 23;
    dp[5] = 62;

    for (int i = 6; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2 + dp[i - 3] * 6 + dp[i - 4] - dp[i - 6] + 1000000007) % 1000000007;
    }
    
    answer = dp[n];
    
    return answer;
}