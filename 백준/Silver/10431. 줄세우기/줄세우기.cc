#include <iostream>

using namespace std;

int P, T, cnt, arr[20];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> P;

	while (P--)
	{
		cnt = 0;

		cin >> T;

		for (int i = 0; i < 20; i++)
		{
			cin >> arr[i];
		}

		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (arr[i] < arr[j])
				{
					cnt++;
				}
			}
		}

		cout << T << " " << cnt << "\n";
	}

	return 0;
}