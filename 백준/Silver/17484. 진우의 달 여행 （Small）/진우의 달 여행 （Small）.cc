#include <iostream>

using namespace std;

const int MAX = 600;
int N, M, result = MAX, arr[6][6], dx[3] = { -1, 0, 1 };

int DFS(int y, int x, int previous)
{
	if (y == N)
	{
		return 0;
	}

	int fuel = MAX;

	for (int i = 0; i < 3; i++)
	{
		if (previous == i || x + dx[i] < 0 || x + dx[i] >= M)
		{
			continue;
		}

		fuel = min(fuel, DFS(y + 1, x + dx[i], i) + arr[y][x]);
	}

	return fuel;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		result = min(result, DFS(0, i, -1));
	}

	cout << result;

	return 0;
}