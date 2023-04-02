#include <string>
#include <regex>

using namespace std;

int solution(string str1, string str2)
{
	int answer = 0;
	vector<string> v1;
	vector<string> v2;

	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

	for (int i = 0; i < str1.length() - 1; i++)
	{
		if (regex_search(str1.substr(i, 2), regex("[^a-z]")))
		{
			continue;
		}

		v1.push_back(str1.substr(i, 2));
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		if (regex_search(str2.substr(i, 2), regex("[^a-z]")))
		{
			continue;
		}

		v2.push_back(str2.substr(i, 2));
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<string> v3;
	v3.resize(v1.size() + v2.size());
	auto itr = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	v3.erase(itr, v3.end());

	vector<string> v4;
	v4.resize(v1.size() + v2.size());
	itr = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	v4.erase(itr, v4.end());

	if (v3.size() == 0 && v4.size() == 0)
	{
		answer = 65536;
	}
	else
	{
		answer = (static_cast<float>(v3.size()) / v4.size()) * 65536;
	}

	return answer;
}