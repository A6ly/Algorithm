#include <iostream>

using namespace std;

int N, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= 500; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (((i * i) - (j * j) - N) == 0)
			{
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}