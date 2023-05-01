#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 50;
int N, L, R, A[MAX][MAX], dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 }, day;
bool visit[MAX][MAX], isMove;

void BFS(int startY, int startX)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> vec;
	int sum = A[startY][startX];

	visit[startY][startX] = true;
	q.push({ startY, startX });
	vec.push_back({ startY, startX });

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int diff = abs(A[y][x] - A[ny][nx]);

			if (0 <= ny && ny < N && 0 <= nx && nx < N && !visit[ny][nx] && diff >= L && diff <= R)
			{
				visit[ny][nx] = true;
				isMove = true;
				sum += A[ny][nx];

				q.push({ ny, nx });
				vec.push_back({ ny, nx });
			}
		}
	}

	if (isMove)
	{
		int people = sum / vec.size();

		for (int i = 0; i < vec.size(); i++)
		{
			A[vec[i].first][vec[i].second] = people;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}

	while (true)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!visit[i][j])
				{
					BFS(i, j);
				}
			}
		}

		if (isMove)
		{
			memset(visit, false, sizeof(visit));
			isMove = false;

			day++;
		}
		else
		{
			break;
		}
	}

	cout << day;

	return 0;
}