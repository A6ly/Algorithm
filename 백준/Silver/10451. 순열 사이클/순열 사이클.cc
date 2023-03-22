#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1001;
int T, N, result;
vector<int> vec[MAX];
bool visit[MAX];

void DFS(int node)
{
	visit[node] = true;

	for (int i = 0; i < vec[node].size(); i++)
	{
		int temp = vec[node][i];
		if (!visit[temp])
			DFS(temp);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		result = 0;

		for (int i = 1; i <= N; i++)
		{
			vec[i].clear();
		}

		memset(visit, false, sizeof(visit));

		cin >> N;

		for (int i = 1; i <= N; i++)
		{
			int v;

			cin >> v;

			vec[i].push_back(v);
		}

		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
			{
				result++;

				DFS(i);
			}
		}

		cout << result << "\n";
	}

	return 0;
}