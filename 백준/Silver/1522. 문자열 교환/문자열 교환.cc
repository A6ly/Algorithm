#include <iostream>
#include <algorithm>

using namespace std;

string str;
int result = 1000;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;

	int length = str.length();
	int aCnt = count(str.begin(), str.end(), 'a');

	for (int i = 0; i < length; i++)
	{
		int cntA = aCnt, cntB = 0;

		for (int j = i; j < i + length; j++)
		{
			if (cntA == 0)
			{
				break;
			}
			else if (str[j % length] == 'b')
			{
				cntA--;
				cntB++;
			}
			else
			{
				cntA--;
			}
		}

		result = min(result, cntB);
	}

	cout << result;

	return 0;
}