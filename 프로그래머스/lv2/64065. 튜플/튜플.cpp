#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b) {
	return a.size() < b.size();
}

vector<int> solution(string s)
{
	vector<int> answer;
	vector<int> innerVec;
	vector<vector<int>> vec;

	for (int i = 1; i < s.length() - 1; i++)
	{
		char c = s[i];

		if (isdigit(c))
		{
			int num = c - '0';
			i++;

			while (isdigit(s[i]))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}

			innerVec.push_back(num);
			i--;
		}
		else if (c == '{')
		{
			innerVec = vector<int>();
		}
		else if (c == '}')
		{
			vec.push_back(innerVec);
		}
	}

	sort(vec.begin(), vec.end(), comp);

	for (int i = 1; i < vec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < vec[j].size(); k++)
			{
				vec[i].erase(remove(vec[i].begin(), vec[i].end(), vec[j][k]), vec[i].end());
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		answer.push_back(vec[i][0]);
	}

	return answer;
}