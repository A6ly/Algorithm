#include <iostream>

using namespace std;

const int MAX = 11;
int N, arr[MAX][MAX], result = 10000000;
bool visit[MAX];

void DFS(int start, int row, int sum, int count)
{
	if (!visit[row])
	{
		visit[row] = true;

		for (int col = 1; col <= N; col++)
		{
			if (arr[row][col])
			{
				DFS(start, col, sum + arr[row][col], count + 1);
			}
		}

		visit[row] = false;
	}

	if (start == row && count == N)
	{
		result = min(result, sum);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(i, i, 0, 0);
	}

	cout << result;

	return 0;
}