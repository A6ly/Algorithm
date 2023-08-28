#include <iostream>

using namespace std;

int a, b, c, d, minute, second;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c >> d;

	minute = a + b + c + d;

	second = minute % 60;

	minute /= 60;

	cout << minute << "\n" << second;
}