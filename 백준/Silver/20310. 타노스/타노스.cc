#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> s;

	int length = s.length();
	int zeroHalfCount = count(s.begin(), s.end(), '0') / 2;
	int oneHalfCount = count(s.begin(), s.end(), '1') / 2;

	for (int i = length - 1; i >= 0; i--)
	{
		if (s[i] == '0' && zeroHalfCount > 0)
		{
			s[i] = '2';

			zeroHalfCount--;
		}
	}

	for (int i = 0; i < length; i++)
	{
		if (s[i] == '1' && oneHalfCount > 0)
		{
			s[i] = '2';

			oneHalfCount--;
		}
	}

	s.erase(remove(s.begin(), s.end(), '2'), s.end());

	cout << s;

	return 0;
}