#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 50001;
int N, M, A, B, C, barn, cow, nBarn, nCow, arr[MAX];
vector<vector<pair<int, int>>> vec(MAX);

void Dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 1, 0 });

	while (!pq.empty())
	{
		barn = pq.top().first;
		cow = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[barn].size(); i++)
		{
			nBarn = vec[barn][i].first;
			nCow = vec[barn][i].second;

			if (arr[nBarn] > arr[barn] + nCow)
			{
				arr[nBarn] = arr[barn] + nCow;
				pq.push({ nBarn, nCow });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	fill(arr + 2, arr + MAX, 50000000);

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;

		vec[A].push_back({ B, C });
		vec[B].push_back({ A, C });
	}

	Dijkstra();

	cout << arr[N];

	return 0;
}