#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, arr[101];
bool visit[101];
vector<int> vec;

void DFS(int start, int current)
{
	if (visit[current])
	{
		if (current == start)
		{
			vec.push_back(start);
		}
	}
	else
	{
		visit[current] = true;

		DFS(start, arr[current]);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++)
	{
		DFS(i, i);
		memset(visit, false, sizeof(visit));
	}

	cout << vec.size() << "\n";

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << "\n";
	}

	return 0;
}