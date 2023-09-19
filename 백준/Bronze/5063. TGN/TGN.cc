#include <iostream>

using namespace std;

int N, r, e, c;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N--)
	{
		cin >> r >> e >> c;

		if (e - r > c)
		{
			cout << "advertise\n";
		}
		else if (e - r < c)
		{
			cout << "do not advertise\n";
		}
		else
		{
			cout << "does not matter\n";
		}
	}
}