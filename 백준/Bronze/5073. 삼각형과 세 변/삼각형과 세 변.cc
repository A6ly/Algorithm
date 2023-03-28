#include <iostream>
#include <algorithm>

using namespace std;

int a, b, c;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> a >> b >> c;

		if (a + b + c == 0)
		{
			break;
		}
		else if (a == b && b == c)
		{
			cout << "Equilateral\n";
		}
		else if (2 * max({ a, b, c }) >= a + b + c)
		{
			cout << "Invalid\n";
		}
		else if (a == b || b == c || a == c)
		{
			cout << "Isosceles\n";
		}
		else
		{
			cout << "Scalene\n";
		}
	}

	return 0;
}