#include <iostream>

using namespace std;

int N, cnt, result = 500000;
bool check;
char ch[2] = { 'R', 'B' };
string str;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> str;

	for (int i = 0; i < 2; i++)
	{
		cnt = 0;
		check = false;

		for (int j = 0; j < N; j++)
		{
			if (str[j] == ch[i] && check)
			{
				cnt++;
			}
			else if (str[j] != ch[i])
			{
				check = true;
			}
		}

		result = min(result, cnt);

		cnt = 0;
		check = false;

		for (int j = N - 1; j >= 0; j--)
		{
			if (str[j] == ch[i] && check)
			{
				cnt++;
			}
			else if (str[j] != ch[i])
			{
				check = true;
			}
		}

		result = min(result, cnt);
	}

	cout << result;

	return 0;
}