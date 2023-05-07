#include <iostream>

using namespace std;

long long S, N;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;

	while (S >= 0)
	{
		N++;
		S -= N;
	}

	cout << N - 1;

	return 0;
}