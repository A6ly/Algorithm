#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string str;
map<string, int> m;

bool comp(pair<string, int>& a, pair<string, int>& b)
{
	if (a.second == b.second)
	{
		if (a.first.length() == b.first.length())
		{
			return a.first < b.first;
		}
		else
		{
			return a.first.length() > b.first.length();
		}
	}

	return a.second > b.second;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		if (str.length() >= M)
		{
			if (m.find(str) != m.end())
			{
				m.find(str)->second++;
			}
			else
			{
				m.insert({ str, 1 });
			}
		}
	}

	vector<pair<string, int>> vec(m.begin(), m.end());

	sort(vec.begin(), vec.end(), comp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].first << "\n";
	}

	return 0;
}