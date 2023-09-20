#include <iostream>

using namespace std;

int N, result;
char candy[50][50], temp;

void Count()
{
	char current;
	int cnt;

	for (int i = 0; i < N; i++)
	{
		current = candy[i][0];
		cnt = 1;

		for (int j = 0; j < N - 1; j++)
		{
			if (candy[i][j] == candy[i][j + 1])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}

			current = candy[i][j];

			result = max(result, cnt);
		}
	}

	for (int i = 0; i < N; i++)
	{
		current = candy[0][i];
		cnt = 1;

		for (int j = 0; j < N - 1; j++)
		{
			if (candy[j][i] == candy[j + 1][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}

			current = candy[j][i];

			result = max(result, cnt);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> candy[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (candy[i][j] != candy[i][j + 1])
			{
				temp = candy[i][j];
				candy[i][j] = candy[i][j + 1];
				candy[i][j + 1] = temp;

				Count();

				temp = candy[i][j];
				candy[i][j] = candy[i][j + 1];
				candy[i][j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (candy[j][i] != candy[j + 1][i])
			{
				temp = candy[j][i];
				candy[j][i] = candy[j + 1][i];
				candy[j + 1][i] = temp;

				Count();

				temp = candy[j][i];
				candy[j][i] = candy[j + 1][i];
				candy[j + 1][i] = temp;
			}
		}
	}

	cout << result;

	return 0;
}