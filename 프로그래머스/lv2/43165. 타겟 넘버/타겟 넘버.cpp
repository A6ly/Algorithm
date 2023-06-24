#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target)
{
	int answer = 0;
	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int currentIndex = q.front().first;
		int currentSum = q.front().second;
		q.pop();

		if (currentIndex == numbers.size())
		{
			if (currentSum == target)
			{
				answer++;
			}
		}
		else
		{
			int num = numbers[currentIndex];
			q.push({ currentIndex + 1, currentSum + num });
			q.push({ currentIndex + 1, currentSum - num });
		}
	}

	return answer;
}