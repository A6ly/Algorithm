#include <iostream>
#include <queue>

using namespace std;

int T, l, startX, startY, endX, endY, arr[300][300], dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 }, dx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ startY, startX });
	arr[startY][startX] = 0;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < l && ny >= 0 && nx < l && nx >= 0)
			{
				if (arr[ny][nx] > arr[y][x] + 1)
				{
					arr[ny][nx] = arr[y][x] + 1;

					q.push({ ny, nx });
				}
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> l >> startX >> startY >> endX >> endY;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < l; j++)
			{
				arr[i][j] = 300;
			}
		}

		BFS();

		cout << arr[endY][endX] << "\n";
	}

	return 0;
}