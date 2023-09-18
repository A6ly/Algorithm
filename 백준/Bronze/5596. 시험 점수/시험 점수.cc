#include <iostream>

using namespace std;

int S, T, score;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 4; i++)
	{
		cin >> score;

		S += score;
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> score;

		T += score;
	}

	if (S > T)
	{
		cout << S;
	}
	else if (S < T)
	{
		cout << T;
	}
	else
	{
		cout << S;
	}
}