#include <string>
#include <vector>

using namespace std;

string answer = "";
pair<int, int> rightFinger = { 3, 0 }, leftFinger = { 3, 2 };

void middleNumber(int y, int x, string hand)
{
	int rightDistance = abs(rightFinger.first - y) + abs(rightFinger.second - x);
	int leftDistance = abs(leftFinger.first - y) + abs(leftFinger.second - x);

	if (rightDistance < leftDistance)
	{
		rightFinger = { y, x };
		answer += 'R';
	}
	else if (rightDistance > leftDistance)
	{
		leftFinger = { y, x };
		answer += 'L';
	}
	else
	{
		if (hand == "right")
		{
			rightFinger = { y, x };
			answer += 'R';
		}
		else if (hand == "left")
		{
			leftFinger = { y, x };
			answer += 'L';
		}
	}
}

string solution(vector<int> numbers, string hand)
{
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 0)
		{
			middleNumber(3, 1, hand);
		}
		else if (numbers[i] == 1)
		{
			leftFinger = { 0, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 2)
		{
			middleNumber(0, 1, hand);
		}
		else if (numbers[i] == 3)
		{
			rightFinger = { 0, 2 };
			answer += 'R';
		}
		else if (numbers[i] == 4)
		{
			leftFinger = { 1, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 5)
		{
			middleNumber(1, 1, hand);
		}
		else if (numbers[i] == 6)
		{
			rightFinger = { 1, 2 };
			answer += 'R';
		}
		else if (numbers[i] == 7)
		{
			leftFinger = { 2, 0 };
			answer += 'L';
		}
		else if (numbers[i] == 8)
		{
			middleNumber(2, 1, hand);
		}
		else if (numbers[i] == 9)
		{
			rightFinger = { 2, 2 };
			answer += 'R';
		}
	}

	return answer;
}