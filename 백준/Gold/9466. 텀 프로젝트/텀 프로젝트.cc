#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, n, cnt;
bool visit[100001], complete[100001];
vector<int> vec;

void DFS(int num)
{
	visit[num] = true;
	int next = vec[num];

	if (!visit[next])
	{
		DFS(next);
	}
	else if (!complete[next])
	{
		for (int i = next; i != num; i = vec[i])
		{
			cnt++;
		}

		cnt++;
	}

	complete[num] = true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> n;

		vec = vector<int>(n + 1, 0);
		memset(visit, false, sizeof(visit));
		memset(complete, false, sizeof(complete));
		cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			cin >> vec[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				DFS(i);
			}
		}

		cout << n - cnt << "\n";
	}

	return 0;
}