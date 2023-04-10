#include <iostream>
#include <algorithm>

using namespace std;

string s, result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;

	int zeroHalfCount = count(s.begin(), s.end(), '0') / 2;
	int oneHalfCount = count(s.begin(), s.end(), '1') / 2;

	for (int i = 0; i < zeroHalfCount; i++)
	{
		result += '0';
	}

	for (int i = 0; i < oneHalfCount; i++)
	{
		result += '1';
	}

	cout << result;

	return 0;
}