#include <iostream>
#include <stack>

using namespace std;

int N, height;
stack<pair<int, int>> s;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> height;

		while (!s.empty())
		{
			if (s.top().second > height)
			{
				cout << s.top().first << " ";

				break;
			}

			s.pop();
		}

		if (s.empty())
		{
			cout << 0 << " ";
		}

		s.push({ i, height });
	}

	return 0;
}