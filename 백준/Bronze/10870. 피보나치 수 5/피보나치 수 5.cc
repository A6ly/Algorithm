#include <iostream>

using namespace std;

int n, a = 0, b = 1, c;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	if (n < 2)
	{
		if (n == 0)
			cout << 0;
		else
			cout << 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}

		cout << c;
	}

	return 0;
}