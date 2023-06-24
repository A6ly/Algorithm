#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> maps)
{
	int answer = 0;
	int endY = maps.size(), endX = maps[0].size();
	int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	vector<vector<int>> vec(endY, vector<int>(endX, -1));
	vec[0][0] = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny >= 0 && nx >= 0 && ny < endY && nx < endX && maps[ny][nx] == 1)
			{
				if (vec[ny][nx] == -1)
				{
					vec[ny][nx] = vec[y][x] + 1;
					q.push({ ny, nx });
				}
			}
		}
	}

	answer = vec[endY - 1][endX - 1];

	return answer;
}