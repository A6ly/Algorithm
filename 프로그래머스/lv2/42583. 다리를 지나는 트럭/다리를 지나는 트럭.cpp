#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
	int answer = 0;
	int currentWeight = 0;
	queue<int> q;
	answer = bridge_length;

	for (int i = 0; i < truck_weights.size(); i++)
	{
		while (true)
		{
			if (bridge_length == q.size())
			{
				currentWeight -= q.front();
				q.pop();
			}

			if (currentWeight + truck_weights[i] <= weight)
			{
				q.push(truck_weights[i]);
				currentWeight += truck_weights[i];
				answer++;

				break;
			}
			else
			{
				q.push(0);
				answer++;
			}
		}
	}

	return answer;
}