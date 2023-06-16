#include <iostream>

using namespace std;

int N, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N >= 5)
	{
		cnt += N / 5;
		N /= 5;
	}

	cout << cnt;

	return 0;
}