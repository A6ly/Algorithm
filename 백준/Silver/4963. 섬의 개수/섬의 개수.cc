#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int w, h, cnt, arr[50][50], dy[8] = { -1, 1, 0, 0, 1, 1, -1, -1 }, dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
bool visit[50][50];

void BFS(int startY, int startX)
{
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	visit[startY][startX] = true;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < h && ny >= 0 && nx < w && nx >= 0 && arr[ny][nx] && !visit[ny][nx])
			{
				visit[ny][nx] = true;
				q.push({ ny, nx });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}

		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
		cnt = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (arr[i][j] && !visit[i][j])
				{
					cnt++;
					BFS(i, j);
				}
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}