#include <iostream>

using namespace std;

int N, dy[4] = { 1, -1, 0, 0, }, dx[4] = { 0, 0, -1, 1 }, leftArm, rightArm, waist, leftLeg, rightLeg;
char arr[1001][1001];

pair<int, int> FindHeartPosition()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] == '*')
			{
				int cnt = 0;

				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && arr[ny][nx] == '*')
					{
						cnt++;
					}
				}

				if (cnt == 4)
				{
					cout << i << " " << j << "\n";

					return { i, j };
				}
			}
		}
	}
}

void BodyMeasurements(pair<int, int> heart)
{
	int y = heart.first;
	int x = heart.second;

	for (int i = x - 1; i >= 1; i--)
	{
		if (arr[y][i] == '*')
		{
			leftArm++;
		}

		if (arr[y][i] == '_' || i == 1)
		{
			cout << leftArm << " ";

			break;
		}
	}

	for (int i = x + 1; i <= N; i++)
	{
		if (arr[y][i] == '*')
		{
			rightArm++;
		}

		if (arr[y][i] == '_' || i == N)
		{
			cout << rightArm << " ";

			break;
		}
	}

	for (int i = y + 1; i <= N; i++)
	{
		if (arr[i][x] == '*')
		{
			waist++;
		}
		else if (arr[i][x] == '_' || i == N)
		{
			cout << waist << " ";

			break;
		}
	}

	for (int i = y + waist + 1; i <= N; i++)
	{
		if (arr[i][x - 1] == '*')
		{
			leftLeg++;
		}

		if (arr[i][x - 1] == '_' || i == N)
		{
			cout << leftLeg << " ";

			break;
		}
	}

	for (int i = y + waist + 1; i <= N; i++)
	{
		if (arr[i][x + 1] == '*')
		{
			rightLeg++;
		}

		if (arr[i][x + 1] == '_' || i == N)
		{
			cout << rightLeg << " ";

			break;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	BodyMeasurements(FindHeartPosition());

	return 0;
}