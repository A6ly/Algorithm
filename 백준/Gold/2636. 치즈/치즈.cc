#include <iostream>
#include <queue>

using namespace std;

int maxY, maxX, lastCnt, cnt, hour, arr[100][100], dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
bool visit[100][100];

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

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < maxY && nx < maxX && !visit[ny][nx])
			{
				if (arr[ny][nx] == 0)
				{
					q.push({ ny, nx });
				}
				else if (arr[ny][nx] == 1)
				{
					arr[ny][nx] = 2;
				}

				visit[ny][nx] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> maxY >> maxX;

	for (int i = 0; i < maxY; i++)
	{
		for (int j = 0; j < maxX; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	while (true)
	{
		if (cnt == 0)
		{
			cout << hour << "\n" << lastCnt;

			break;
		}

		lastCnt = cnt;

		for (int i = 0; i < maxY; i++)
		{
			for (int j = 0; j < maxX; j++)
			{
				if (arr[i][j] == 0 && !visit[i][j])
				{
					BFS(0, 0);
				}
			}
		}

		for (int i = 0; i < maxY; i++)
		{
			for (int j = 0; j < maxX; j++)
			{
				if (arr[i][j] == 2)
				{
					arr[i][j] = 0;
					cnt--;
				}

				visit[i][j] = false;
			}
		}

		hour++;
	}

	return 0;
}