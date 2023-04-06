#include <iostream>

using namespace std;

int N, K, cnt;
string str;
bool isExit;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> str;

	for (int i = 0; i < N; i++)
	{
		if (str.at(i) == 'P')
		{
			for (int j = K; j > 0; j--)
			{
				if ((i - j) >= 0 && str.at(i - j) == 'H')
				{
					str.at(i) = 'X';
					str.at(i - j) = 'X';
					cnt++;
					isExit = true;

					break;
				}
			}

			if (isExit)
			{
				isExit = false;

				continue;
			}

			for (int j = 1; j <= K; j++)
			{
				if ((i + j) < N && str.at(i + j) == 'H')
				{
					str.at(i) = 'X';
					str.at(i + j) = 'X';
					cnt++;

					break;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}