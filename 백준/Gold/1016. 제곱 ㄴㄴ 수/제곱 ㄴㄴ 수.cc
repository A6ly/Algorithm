#include <iostream>

using namespace std;

const int MAX = 1000001;
long long minV, maxV;
bool arr[MAX];
int cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> minV >> maxV;

	for (long long i = 2; i * i <= maxV; i++)
	{
		long long num = minV / (i * i);

		if (minV % (i * i) != 0)
		{
			num++;
		}

		while (num * i * i <= maxV)
		{
			arr[num * i * i - minV] = true;
			num++;
		}
	}

	for (long long i = minV; i <= maxV; i++)
	{
		if (!arr[i - minV])
		{
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}