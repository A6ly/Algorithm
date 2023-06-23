#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations)
{
	vector<int> answer;
	multiset<int> ms;

	for (int i = 0; i < operations.size(); i++)
	{
		string operation;
		string numStr;
		stringstream stream;
		stream.str(operations[i]);
		stream >> operation;
		stream >> numStr;
		int num = stoi(numStr);

		if (operation == "I")
		{
			ms.insert(num);
		}
		else if (!ms.empty())
		{
			if (num == 1)
			{
				auto iter = ms.end();
				iter--;
				ms.erase(iter);
			}
			else
			{
				ms.erase(ms.begin());
			}
		}
	}

	if (!ms.empty())
	{
		auto iter = ms.end();
		iter--;

		answer.push_back(*iter);
		answer.push_back(*ms.begin());
	}
	else
	{
		answer.push_back(0);
		answer.push_back(0);
	}

	return answer;
}