#include <iostream>

using namespace std;

int m, f;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> m >> f;

		if (m == 0 && f == 0)
		{
			break;
		}

		cout << m + f << '\n';
	}
}