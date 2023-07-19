#include <iostream>
#include <string>

using namespace std;

int T, n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> n;

		string str = "";

		while (n > 0)
		{
			int r = n % 2;
			str += to_string(r);
			n /= 2;
		}

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '1')
			{
				cout << i;

				if (i != str.length() - 1)
				{
					cout << " ";
				}
			}
		}

		cout << "\n";
	}

	return 0;
}