#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 300001;
int N, M, K, X, A, B, dist[MAX];
bool noCity = true;
vector<int> vec[MAX];

void Dijkstra(int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int current = q.front();
		q.pop();

		for (int i = 0; i < vec[current].size(); i++)
		{
			int next = vec[current][i];

			if (dist[next] > dist[current] + 1)
			{
				dist[next] = dist[current] + 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;

		vec[A].push_back(B);
	}

	for (int i = 1; i <= N; i++)
	{
		dist[i] = MAX;
	}

	Dijkstra(X);

	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == K)
		{
			cout << i << "\n";

			noCity = false;
		}
	}

	if (noCity)
	{
		cout << -1;
	}

	return 0;
}