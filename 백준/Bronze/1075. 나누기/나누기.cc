#include <iostream>

using namespace std;

int N, F;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> F;

	int num = N;

	for (int i = 0; i < 100; i++)
	{
		int result = (num / 100) * 100 + i;

		if (result % F == 0)
		{
			if (i < 10)
			{
				cout << "0" << i;
			}
			else
			{
				cout << i;
			}

			break;
		}
	}

	return 0;
}