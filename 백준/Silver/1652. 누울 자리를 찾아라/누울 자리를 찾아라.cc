#include <iostream>

using namespace std;

int N, cnt, width, length;
char arr[101][101];
string str;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		for (int j = 0; j < N; j++)
		{
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		cnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (cnt >= 2 && arr[i][j] == 'X')
			{
				width++;

				cnt = 0;
			}
			else if (cnt < 2 && arr[i][j] == 'X')
			{
				cnt = 0;
			}
			else if (arr[i][j] == '.')
			{
				cnt++;

				if (cnt >= 2 && j == N - 1)
				{
					width++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cnt = 0;

		for (int j = 0; j < N; j++)
		{
			if (cnt >= 2 && arr[j][i] == 'X')
			{
				length++;

				cnt = 0;
			}
			else if (cnt < 2 && arr[j][i] == 'X')
			{
				cnt = 0;
			}
			else if (arr[j][i] == '.')
			{
				cnt++;

				if (cnt >= 2 && j == N - 1)
				{
					length++;
				}
			}
		}
	}

	cout << width << " " << length;

	return 0;
}