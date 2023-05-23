#include <iostream>

using namespace std;

int A, B, cnt = 1;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;

	while (true)
	{
		if (A == B)
		{
			cout << cnt;

			break;
		}
		else if (A > B)
		{
			cout << -1;

			break;
		}
		else if (B % 10 == 1)
		{
			B /= 10;
		}
		else if (B % 2 == 0)
		{
			B /= 2;
		}
		else
		{
			cout << -1;

			break;
		}

		cnt++;
	}

	return 0;
}