#include <vector>
#include <algorithm>

using namespace std;

int checkRank(int count)
{
	if (count == 6)
	{
		return 1;
	}
	else if (count == 5)
	{
		return 2;
	}
	else if (count == 4)
	{
		return 3;
	}
	else if (count == 3)
	{
		return 4;
	}
	else if (count == 2)
	{
		return 5;
	}
	else
	{
		return 6;
	}
}

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
	vector<int> answer;
	int zeroCount = count(lottos.begin(), lottos.end(), 0), count = 0;

	for (int i = 0; i < win_nums.size(); i++)
	{
		if (find(lottos.begin(), lottos.end(), win_nums[i]) != lottos.end())
		{
			count++;
		}
	}

	int max = zeroCount + count, min = count;

	answer.push_back(checkRank(max));
	answer.push_back(checkRank(min));

	return answer;
}