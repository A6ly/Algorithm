#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	map <string, string> m;
	vector<pair<string, string>> vec;

	for (int i = 0; i < record.size(); i++)
	{
		int firstIndex = record[i].find(' ');
		int secondIndex = record[i].find(' ', firstIndex + 1);

		string header = record[i].substr(0, firstIndex);
		string id = record[i].substr(firstIndex + 1, secondIndex - firstIndex - 1);

		if (header == "Enter")
		{
			string name = record[i].substr(secondIndex + 1);
			m[id] = name;
			vec.push_back({ id, "님이 들어왔습니다." });

		}
		else if (header == "Leave")
		{
			vec.push_back({ id, "님이 나갔습니다." });
		}
		else if (header == "Change")
		{
			string name = record[i].substr(secondIndex + 1);
			m[id] = name;
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i].first = m[vec[i].first];
		answer.push_back(vec[i].first + vec[i].second);
	}

	return answer;
}