#include <iostream>

using namespace std;

int N, result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i *= 10)
	{
		result += N - i + 1;
	}

	cout << result;

	return 0;
}