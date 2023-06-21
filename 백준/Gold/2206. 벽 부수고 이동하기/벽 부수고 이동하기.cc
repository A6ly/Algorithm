#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;
string str;
int N, M, arr[MAX][MAX], path[MAX][MAX][2], dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 }, result = -1;

struct block
{
	int y, x, wall;
};

void BFS(int startX, int startY)
{
	queue<block> q;
	q.push({ startX, startY, 0 });
	path[startX][startY][0] = 1;

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int wall = q.front().wall;
		q.pop();

		if (y == N && x == M)
		{
			result = path[y][x][wall];

			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny <= N && nx <= M && ny >= 1 && nx >= 1)
			{
				if (arr[ny][nx] == 1 && wall == 0)
				{
					path[ny][nx][wall + 1] = path[y][x][wall] + 1;
					q.push({ ny, nx, wall + 1 });
				}
				else if (arr[ny][nx] == 0 && path[ny][nx][wall] == 0)
				{
					path[ny][nx][wall] = path[y][x][wall] + 1;
					q.push({ ny, nx, wall });
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			arr[i][j + 1] = str[j] - '0';
		}
	}

	BFS(1, 1);

	cout << result;

	return 0;
}