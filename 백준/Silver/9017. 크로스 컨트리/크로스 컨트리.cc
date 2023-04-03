#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		int minVal = INT32_MAX, result = 0;
		vector<int> vec;
		vector<vector<int>> vec2(201);

		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int num;

			cin >> num;

			vec.push_back(num);
		}

		for (int i = 1; i <= N; i++)
		{
			if (count(vec.begin(), vec.end(), i) < 6)
			{
				vec.erase(remove(vec.begin(), vec.end(), i), vec.end());
			}
		}

		for (int i = 0; i < vec.size(); i++)
		{
			vec2[vec[i]].push_back(i + 1);
		}

		for (int i = 1; i <= 200; i++)
		{
			int sum = 0;

			if (vec2[i].empty())
			{
				continue;
			}

			for (int j = 0; j < 4; j++)
			{
				sum += vec2[i][j];
			}

			if (sum < minVal)
			{
				minVal = sum;
				result = i;
			}
			else if (sum == minVal)
			{
				if (vec2[i][4] < vec2[result][4])
				{
					minVal = sum;
					result = i;
				}
			}
		}

		cout << result << "\n";
	}

	return 0;
}