#include <iostream>
#include <queue>

using namespace std;

int arr[9][9];
bool row[9][10], col[9][10], square[9][10];

bool Check(int y, int x, int num)
{
	return !row[y][num] && !col[x][num] && !square[y / 3 * 3 + x / 3][num];
}

bool DFS(int cnt)
{
	if (cnt == 81)
	{
		return true;
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (arr[y][x] == 0)
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(y, x, i))
			{
				arr[y][x] = i;
				row[y][i] = true;
				col[x][i] = true;
				square[y / 3 * 3 + x / 3][i] = true;

				if (DFS(cnt + 1))
				{
					return true;
				}

				arr[y][x] = 0;
				row[y][i] = false;
				col[x][i] = false;
				square[y / 3 * 3 + x / 3][i] = false;
			}
		}
	}
	else
	{
		if (DFS(cnt + 1))
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] != 0)
			{
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				square[i / 3 * 3 + j / 3][arr[i][j]] = true;
			}
		}
	}

	DFS(0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}