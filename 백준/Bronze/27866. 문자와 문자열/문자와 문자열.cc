#include <iostream>

using namespace std;

string S;
int i;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S >> i;

	cout << S[i - 1];

	return 0;
}