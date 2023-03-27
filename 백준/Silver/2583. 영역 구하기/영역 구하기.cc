#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;
int M, N, K, lx, ly, rx, ry, dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 }, cnt;
bool arr[MAX][MAX], visit[MAX][MAX];
queue<pair<int, int>> q;
vector<int> result;

void BFS(int startY, int startX)
{
	int area = 1;
	visit[startY][startX] = true;
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

			if (0 <= ny && ny < M && 0 <= nx && nx < N && !arr[ny][nx] && !visit[ny][nx])
			{
				visit[ny][nx] = true;

				q.push({ ny, nx });

				area++;
			}
		}
	}

	result.push_back(area);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;

	while (K--)
	{
		cin >> lx >> ly >> rx >> ry;

		for (int i = ly; i < ry; i++)
		{
			for (int j = lx; j < rx; j++)
			{
				arr[i][j] = true;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!arr[i][j] && !visit[i][j])
			{
				BFS(i, j);

				cnt++;
			}
		}
	}

	cout << cnt << "\n";

	sort(result.begin(), result.end());

	for (int i = 0; i < cnt; i++)
	{
		cout << result[i] << " ";
	}

	return 0;
}