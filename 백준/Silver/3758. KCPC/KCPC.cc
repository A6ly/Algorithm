#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;
int TestData, n, k, t, m, id, num, score, arr[MAX][MAX], sum[MAX];
vector<vector<int>> vec(MAX);
vector<pair<int, int>> competitionResults;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		if (vec[a.first].size() == vec[b.first].size())
		{
			return vec[a.first].back() > vec[b.first].back();
		}

		return vec[a.first].size() < vec[b.first].size();
	}

	return a.second > b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> TestData;

	while (TestData--)
	{
		cin >> n >> k >> t >> m;

		while (m--)
		{
			cin >> id >> num >> score;

			if (arr[id][num] < score)
			{
				arr[id][num] = score;
			}

			vec[id].push_back(m);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				sum[i] += arr[i][j];
			}

			competitionResults.push_back({ i, sum[i] });
		}

		sort(competitionResults.begin(), competitionResults.end(), comp);

		for (int i = 0; i < competitionResults.size(); i++)
		{
			if (competitionResults[i].first == t)
			{
				cout << i + 1 << "\n";

				break;
			}
		}

		memset(arr, 0, sizeof(arr));
		memset(sum, 0, sizeof(sum));

		vec = vector<vector<int>>(MAX);
		competitionResults = vector<pair<int, int>>();
	}

	return 0;
}