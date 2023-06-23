#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<int> q;

	for (int i = 0; i < progresses.size(); i++)
	{
		double work = static_cast<double>(100 - progresses[i]) / static_cast<double>(speeds[i]);
		q.push(ceil(work));
	}

	while (!q.empty())
	{
		int cnt = 1;
		int currentDay = q.front();
		q.pop();

		while (!q.empty() && currentDay >= q.front())
		{
			q.pop();
			cnt++;
		}

		answer.push_back(cnt);
	}

	return answer;
}