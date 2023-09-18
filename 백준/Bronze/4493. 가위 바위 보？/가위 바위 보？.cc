#include <iostream>

using namespace std;

int t, n;
char a, b;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;

	while (t--)
	{
		cin >> n;

		int p1 = 0, p2 = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;

			if (a == 'R')
			{
				if (b == 'S')
				{
					p1++;
				}
				else if (b == 'P')
				{
					p2++;
				}
			}
			else if (a == 'S')
			{
				if (b == 'R')
				{
					p2++;
				}
				else if (b == 'P')
				{
					p1++;
				}
			}
			else if (a == 'P')
			{
				if (b == 'R')
				{
					p1++;
				}
				else if (b == 'S')
				{
					p2++;
				}
			}
		}

		if (p1 > p2)
		{
			cout << "Player 1\n";
		}
		else if (p1 < p2)
		{
			cout << "Player 2\n";
		}
		else
		{
			cout << "TIE\n";
		}
	}
}