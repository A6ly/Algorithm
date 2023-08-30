#include <iostream>

using namespace std;

int T, a, b;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cin >> a >> b;

		cout << "Case " << i << ": " << a + b << "\n";
	}
}