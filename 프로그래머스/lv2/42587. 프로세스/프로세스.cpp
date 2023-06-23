#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ priorities[i], i });
	}

	while (!q.empty())
	{
		int priority = q.front().first;
		int process = q.front().second;
		q.pop();

		if (priority == *max_element(priorities.begin(), priorities.end()))
		{
			answer++;

			if (process == location)
			{
				break;
			}

			priorities[process] = 0;
		}
		else
		{
			q.push({ priority, process });
		}
	}

	return answer;
}