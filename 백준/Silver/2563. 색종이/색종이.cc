#include <iostream>

using namespace std;

int N, y, x, cnt;
bool arr[100][100];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> y >> x;

		for (int j = y; j < y + 10; j++)
		{
			for (int k = x; k < x + 10; k++)
			{
				if (!arr[j][k])
				{
					cnt++;

					arr[j][k] = true;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}