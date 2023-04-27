#include <iostream>
#include <algorithm>

using namespace std;

string S, T, temp;
bool check;

void Solve(string t)
{
	if (S == t)
	{
		check = true;

		return;
	}
	else if (S.length() >= t.length())
	{
		return;
	}

	if (t[t.length() - 1] == 'A')
	{
		temp = t;
		Solve(temp.erase(temp.length() - 1));
	}

	if (t[0] == 'B')
	{
		temp = t;
		reverse(temp.begin(), temp.end());
		Solve(temp.erase(temp.length() - 1));
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S >> T;

	Solve(T);

	if (check)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}