#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
	vector<int> answer;
	map <int, vector<pair<string, string>>> m;

	int basicTime = fees[0];
	int basicFee = fees[1];
	int extraTime = fees[2];
	int extraFee = fees[3];

	for (int i = 0; i < records.size(); i++)
	{
		string time = records[i].substr(0, 5);
		int num = stoi(records[i].substr(6, 4));
		string history = records[i].substr(11);

		m[num].push_back({ history, time });
	}

	for (auto it = m.begin(); it != m.end(); it++)
	{
		int totalMin = 0, inHour = 0, inMin = 0, fee = 0;
		bool isOut = false;

		for (auto vec_it = it->second.begin(); vec_it != it->second.end(); vec_it++)
		{
			if (vec_it->first == "IN")
			{
				inHour = stoi(vec_it->second.substr(0, 2));
				inMin = stoi(vec_it->second.substr(3, 2));

				isOut = false;
			}
			else if (vec_it->first == "OUT")
			{
				totalMin += (stoi(vec_it->second.substr(0, 2)) - inHour) * 60 + (stoi(vec_it->second.substr(3, 2)) - inMin);

				isOut = true;
			}
		}

		if (!isOut)
		{
			totalMin += (23 - inHour) * 60 + (59 - inMin);
		}

		if (totalMin <= basicTime)
		{
			fee += basicFee;
		}
		else
		{
			fee += basicFee;

			if ((totalMin - basicTime) % extraTime == 0)
			{
				fee += ((totalMin - basicTime) / extraTime) * extraFee;
			}
			else
			{
				fee += ((totalMin - basicTime + extraTime) / extraTime) * extraFee;
			}
		}

		answer.push_back(fee);
	}

	return answer;
}