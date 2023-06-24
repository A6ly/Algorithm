#include <vector>
#include <queue>

using namespace std;

bool visit[200];

void BFS(int start, vector<vector<int>>& computers)
{
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty())
	{
		int computer = q.front();
		q.pop();

		for (int i = 0; i < computers[start].size(); i++)
		{
			if (!visit[i] && computers[computer][i] == 1)
			{
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			BFS(i, computers);
			answer++;
		}
	}

	return answer;
}