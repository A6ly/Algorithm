#include <iostream>

using namespace std;

int a, b, sum, result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
	{
		cin >> a >> b;

		sum -= a;
		sum += b;

		result = max(result, sum);
	}

	cout << result;

	return 0;
}