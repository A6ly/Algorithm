#include <iostream>

using namespace std;

int A, B, C, D;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C >> D;

	int hour = D / 3600;
	D %= 3600;
	int minute = D / 60;
	D %= 60;

	A += hour;
	B += minute;
	C += D;

	if (C > 59)
	{
		B += C / 60;
		C %= 60;
	}

	if (B > 59)
	{
		A += B / 60;
		B %= 60;
	}

	if (A > 23)
	{
		A %= 24;
	}

	cout << A << " " << B << " " << C;

	return 0;
}