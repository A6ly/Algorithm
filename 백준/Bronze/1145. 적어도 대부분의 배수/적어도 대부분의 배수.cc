#include <iostream>

using namespace std;

int arr[5], num, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}

	while (true)
	{
		num++;

		for (int i = 0; i < 5; i++)
		{
			if (num % arr[i] == 0)
			{
				cnt++;

				if (cnt == 3)
				{
					cout << num;

					return 0;
				}
			}
		}

		cnt = 0;
	}
}