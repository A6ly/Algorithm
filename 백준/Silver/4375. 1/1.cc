#include <iostream>

using namespace std;

int n;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> n)
	{
		int temp = 1, cnt = 1;

		while (temp % n != 0)
		{
			temp = temp * 10 + 1;
			temp %= n;

			cnt++;
		}

		cout << cnt << '\n';
	}

	return 0;
}