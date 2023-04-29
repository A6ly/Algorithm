#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int N, K, A, result;
deque<int> durability;
deque<bool> robot;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N * 2; i++)
	{
		cin >> A;

		durability.push_back(A);
		robot.push_back(false);
	}

	while (true)
	{
		durability.push_front(durability.back());
		durability.pop_back();

		robot.push_front(robot.back());
		robot.pop_back();
		robot[N - 1] = false;


		for (int i = N - 2; i >= 0; i--)
		{
			if (robot[i] && !robot[i + 1] && durability[i + 1] > 0)
			{
				robot[i] = false;
				robot[i + 1] = true;
				durability[i + 1]--;
			}

			robot[N - 1] = false;
		}

		if (!robot[0] && durability[0] > 0)
		{
			robot[0] = true;
			durability[0]--;
		}

		result++;

		if (count(durability.begin(), durability.end(), 0) >= K)
		{
			break;
		}
	}

	cout << result;

	return 0;
}