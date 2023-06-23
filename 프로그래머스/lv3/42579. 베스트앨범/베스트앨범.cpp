#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;
	map<string, int> m1;
	map<string, multimap<int, int, greater<int>>> m2;

	for (int i = 0; i < genres.size(); i++)
	{
		m1[genres[i]] += plays[i];
		m2[genres[i]].insert({ plays[i], i });
	}

	vector<pair<int, string>> vec;

	for (auto i : m1)
	{
		vec.push_back({ i.second, i.first });
	}

	sort(vec.begin(), vec.end(), greater<pair<int, string>>());

	for (auto i : vec)
	{
		int cnt = 0;

		for (auto j : m2[i.second])
		{
			answer.push_back(j.second);

			cnt++;

			if (cnt >= 2)
			{
				break;
			}
		}
	}

	return answer;
}