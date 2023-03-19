#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand)
{
	string answer = "";
	pair<int, int> right = { 3, 0 }, left = { 3, 2 };

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0)
		{
			int rightDistance = abs(right.first - 3) + abs(right.second - 1);
			int leftDistance = abs(left.first - 3) + abs(left.second - 1);

			if (rightDistance < leftDistance)
			{
				right = { 3, 1 };
				answer += 'R';
			}
			else if (rightDistance > leftDistance)
			{
				left = { 3, 1 };
				answer += 'L';
			}
			else
			{
				if (hand == "right")
				{
					right = { 3, 1 };
					answer += 'R';
				}
				else if (hand == "left")
				{
					left = { 3, 1 };
					answer += 'L';
				}
			}
		}
		else if (numbers[i] == 1)
		{
			left = { 0, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 2)
		{
			int rightDistance = right.first + abs(right.second - 1);
			int leftDistance = left.first + abs(left.second - 1);

			if (rightDistance < leftDistance)
			{
				right = { 0, 1 };
				answer += 'R';
			}
			else if (rightDistance > leftDistance)
			{
				left = { 0, 1 };
				answer += 'L';
			}
			else
			{
				if (hand == "right")
				{
					right = { 0, 1 };
					answer += 'R';
				}
				else if (hand == "left")
				{
					left = { 0, 1 };
					answer += 'L';
				}
			}
		}
		else if (numbers[i] == 3)
		{
			right = { 0, 2 };
			answer += 'R';
		}
		else if (numbers[i] == 4)
		{
			left = { 1, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 5)
		{
			int rightDistance = abs(right.first - 1) + abs(right.second - 1);
			int leftDistance = abs(left.first - 1) + abs(left.second - 1);

			if (rightDistance < leftDistance)
			{
				right = { 1, 1 };
				answer += 'R';
			}
			else if (rightDistance > leftDistance)
			{
				left = { 1, 1 };
				answer += 'L';
			}
			else
			{
				if (hand == "right")
				{
					right = { 1, 1 };
					answer += 'R';
				}
				else if (hand == "left")
				{
					left = { 1, 1 };
					answer += 'L';
				}
			}
		}
		else if (numbers[i] == 6)
		{
			right = { 1, 2 };
			answer += 'R';
		}
		else if (numbers[i] == 7)
		{
			left = { 2, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 8)
		{
			int rightDistance = abs(right.first - 2) + abs(right.second - 1);
			int leftDistance = abs(left.first - 2) + abs(left.second - 1);

			if (rightDistance < leftDistance)
			{
				right = { 2, 1 };
				answer += 'R';
			}
			else if (rightDistance > leftDistance)
			{
				left = { 2, 1 };
				answer += 'L';
			}
			else
			{
				if (hand == "right")
				{
					right = { 2, 1 };
					answer += 'R';
				}
				else if (hand == "left")
				{
					left = { 2, 1 };
					answer += 'L';
				}
			}
		}
		else if (numbers[i] == 9)
		{
			right = { 2, 2 };
			answer += 'R';
		}
	}

	return answer;
}