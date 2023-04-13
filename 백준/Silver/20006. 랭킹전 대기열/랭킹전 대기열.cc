#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p, m, l, i, j;
string n;
vector<pair<int, string>> players;
vector<vector<pair<int, string>>> rooms(300);

bool comp(pair<int, string>& a, pair<int, string>& b)
{
	return a.second < b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		cin >> l >> n;

		players.push_back({ l, n });
	}

	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (rooms[i].size() == m || players.empty() || players.size() == j)
			{
				sort(rooms[i].begin(), rooms[i].end(), comp);

				break;
			}

			if (rooms[i].empty() || abs(rooms[i][0].first - players[j].first) <= 10)
			{
				rooms[i].push_back(players[j]);
				players.erase(players.begin() + j);
				j--;
			}
		}

		if (players.empty())
		{
			break;
		}
	}

	for (int i = 0; !rooms[i].empty(); i++)
	{
		if (rooms[i].size() == m)
		{
			cout << "Started!\n";
		}
		else
		{
			cout << "Waiting!\n";
		}

		for (int j = 0; j < rooms[i].size(); j++)
		{
			cout << rooms[i][j].first << " " << rooms[i][j].second << "\n";
		}
	}

	return 0;
}