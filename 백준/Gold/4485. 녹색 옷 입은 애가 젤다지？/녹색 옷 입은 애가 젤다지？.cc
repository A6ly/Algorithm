#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N, k, arr[125][125], dist[125][125], dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

void BFS()
{
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dist[0][0] = arr[0][0];

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < N && ny >= 0 && nx < N && nx >= 0)
			{
				if (dist[ny][nx] > dist[y][x] + arr[ny][nx])
				{
					dist[ny][nx] = dist[y][x] + arr[ny][nx];

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

	while (true)
	{
		T++;

		cin >> N;

		if (N == 0)
		{
			break;
		}

		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				dist[i][j] = 1125;
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}
		}

		BFS();

		cout << "Problem " << T << ": " << dist[N - 1][N - 1] << "\n";
	}

	return 0;
}