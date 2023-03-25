#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int N, arr[MAX];
bool visit[MAX];
vector<int> vec[MAX];

void DFS(int start)
{
	visit[start] = true;

	for (int i = 0; i < vec[start].size(); i++)
	{
		int next = vec[start][i];
		if (!visit[next])
		{
			arr[next] = start;

			DFS(next);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int v1, v2;

		cin >> v1 >> v2;

		vec[v1].push_back(v2);
		vec[v2].push_back(v1);
	}

	DFS(1);

	for (int i = 0; i < N - 1; i++)
	{
		cout << arr[i + 2] << "\n";
	}

	return 0;
}