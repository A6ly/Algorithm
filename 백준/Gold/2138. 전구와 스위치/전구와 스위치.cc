#include <iostream>

using namespace std;

const int MAX = 100000;
int N, result;
string str1, str2, goal;

void PressSwitch(string& str, int num)
{
	for (int i = num - 1; i <= num + 1; i++)
	{
		if (i >= 0 && i < N)
		{
			str[i] = str[i] == '0' ? '1' : '0';
		}
	}
}

void Solve()
{
	int cnt = 0;

	PressSwitch(str1, 0);
	cnt++;

	for (int i = 1; i < N; i++)
	{
		if (str1[i - 1] != goal[i - 1])
		{
			PressSwitch(str1, i);

			cnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (str1[i] != goal[i])
		{
			cnt = MAX;

			break;
		}
	}

	result = cnt;
	cnt = 0;

	for (int i = 1; i < N; i++)
	{
		if (str2[i - 1] != goal[i - 1])
		{
			PressSwitch(str2, i);

			cnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (str2[i] != goal[i])
		{
			cnt = MAX;

			break;
		}
	}

	result = min(result, cnt);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> str1 >> goal;

	str2 = str1;

	Solve();

	if (result == MAX)
	{
		cout << -1;
	}
	else
	{
		cout << result;
	}

	return 0;
}