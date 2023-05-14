#include <iostream>

using namespace std;

int N, index = 1, sum, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (index <= N)
	{
		for (int i = index; i <= N; i++)
		{
			sum += i;

			if (sum == N)
			{
				cnt++;

				break;
			}
			else if (sum > N)
			{
				break;
			}
		}

		sum = 0;
		index++;
	}

	cout << cnt;

	return 0;
}