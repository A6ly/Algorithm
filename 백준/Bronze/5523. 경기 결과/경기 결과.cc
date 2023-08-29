#include <iostream>

using namespace std;

int N, aScore, bScore, A, B;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N--)
	{
		cin >> aScore >> bScore;

		if (aScore > bScore)
		{
			A++;
		}
		else if (aScore < bScore)
		{
			B++;
		}
	}

	cout << A << " " << B;
}