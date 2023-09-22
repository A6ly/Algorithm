#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, K, path[100001];
bool visit[100001];
vector<int> vec;

void bfs(int n, int k)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	queue<int> q2;
	q.push({ 0, n });
	visit[n] = true;

	while (!q.empty()) {
		int time = q.top().first;
		int location = q.top().second;
		q.pop();

		if (location == k)
		{
			cout << time << '\n';

			int index = location;
			vec.push_back(location);

			while (index != n)
			{
				vec.push_back(path[index]);

				index = path[index];
			}

			for (int i = vec.size() - 1; i >= 0; i--)
			{
				cout << vec[i] << ' ';
			}
		}

		if (location * 2 < 100001 && !visit[location * 2])
		{
			q.push({ time + 1, location * 2 });
			visit[location * 2] = true;
			path[location * 2] = location;
		}

		if (location + 1 < 100001 && !visit[location + 1])
		{
			q.push({ time + 1, location + 1 });
			visit[location + 1] = true;
			path[location + 1] = location;
		}

		if (location - 1 > -1 && !visit[location - 1])
		{
			q.push({ time + 1, location - 1 });
			visit[location - 1] = true;
			path[location - 1] = location;
		}
	}

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	bfs(N, K);

	return 0;
}