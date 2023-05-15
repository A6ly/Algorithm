#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, F;
vector<int> vec;

int DFS(vector<int> temp)
{
	if (temp.size() == 2)
	{
		return temp[0] + temp[1];
	}

	vector<int> next;

	for (int i = 0; i < temp.size() - 1; i++)
	{
		next.push_back(temp[i] + temp[i + 1]);
	}

	return DFS(next);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> F;

	if (N == 1)
	{
		cout << 1;

		return 0;
	}

	for (int i = 1; i <= N; i++)
	{
		vec.push_back(i);
	}

	do
	{
		if (DFS(vec) == F)
		{
			for (int i = 0; i < vec.size(); i++)
			{
				cout << vec[i] << " ";
			}

			break;
		}
	} while (next_permutation(vec.begin(), vec.end()));

	return 0;
}