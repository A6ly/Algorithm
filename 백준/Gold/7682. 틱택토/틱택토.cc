#include <iostream>

using namespace std;

string str;
char board[3][3];

bool CheckGameResult(char c)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
		{
			return true;
		}
	}

	if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
	{
		return true;
	}

	if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
	{
		return true;
	}

	return false;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> str;

		if (str == "end")
		{
			break;
		}

		int xCnt = 0, oCnt = 0;
		bool xWin = false, oWin = false;

		for (int i = 0; i < 9; i++)
		{
			board[i / 3][i % 3] = str[i];

			if (str[i] == 'X')
			{
				xCnt++;
			}
			else if (str[i] == 'O')
			{
				oCnt++;
			}
		}

		xWin = CheckGameResult('X');
		oWin = CheckGameResult('O');


		if (xWin && !oWin && !(xCnt - oCnt - 1))
		{
			cout << "valid\n";
		}
		else if (!xWin && oWin && xCnt == oCnt)
		{
			cout << "valid\n";
		}
		else if (!xWin && !oWin && xCnt == 5 && oCnt == 4)
		{
			cout << "valid\n";
		}
		else
		{
			cout << "invalid\n";
		}
	}

	return 0;
}