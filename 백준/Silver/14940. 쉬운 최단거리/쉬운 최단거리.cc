#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int n, m, startY, startX, arr[MAX][MAX], result[MAX][MAX], dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };
bool visit[MAX][MAX];
queue<pair<int, int>> q;

void BFS()
{
	visit[startY][startX] = true;
	result[startY][startX] = 0;
	q.push({ startY, startX });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < n && 0 <= nx && nx < m && arr[ny][nx] == 1 && !visit[ny][nx])
			{
				q.push({ ny, nx });
				visit[ny][nx] = true;
				result[ny][nx] = result[y][x] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
		}
	}

	BFS();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1 && !visit[i][j])
			{
				result[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}