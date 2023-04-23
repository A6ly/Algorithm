#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10001;
int N, D, start, arrival, dist;
vector<pair<int, int>> shortcut[MAX];
vector<int> minDist(MAX, MAX);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		cin >> start >> arrival >> dist;

		shortcut[arrival].push_back({ start, dist });
	}

	minDist[0] = 0;

	for (int i = 1; i <= D; i++)
	{
		if (shortcut[i].size() == 0)
		{
			minDist[i] = minDist[i - 1] + 1;
		}
		else
		{
			for (int j = 0; j < shortcut[i].size(); j++)
			{
				minDist[i] = min({ minDist[i], minDist[i - 1] + 1, minDist[shortcut[i][j].first] + shortcut[i][j].second });
			}
		}
	}

	cout << minDist[D];

	return 0;
}