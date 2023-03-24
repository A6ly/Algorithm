#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 101;
int N, M, A, B, arr[MAX][MAX], minValue = INT32_MAX, result;
bool visit[MAX];
vector<int> vec[MAX];
queue<int> q;

void BFS(int start)
{
	visit[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < vec[cur].size(); i++)
		{
			int next = vec[cur][i];

			if (!visit[next])
			{
				visit[next] = true;

				q.push(next);

				arr[start][next] = arr[start][cur] + 1;
				arr[next][start] = arr[cur][start] + 1;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		cin >> A >> B;

		vec[A].push_back(B);
		vec[B].push_back(A);
	}

	for (int i = 1; i <= N; i++)
	{
		BFS(i);
		memset(visit, false, sizeof(visit));
	}

	for (int i = 1; i <= N; i++)
	{
		int sum = 0;

		for (int j = 1; j <= N; j++)
		{
			sum += arr[i][j];
		}

		if (sum < minValue)
		{
			minValue = sum;
			result = i;
		}
	}

	cout << result;

	return 0;
}