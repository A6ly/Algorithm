#include <iostream>

using namespace std;

int K;
string str, result;
char arr[200][200];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> str;

	int index = 0;

	for (int i = 0; i < str.length() / K; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (i % 2 == 0)
			{
				arr[i][j] = str[index + j];
			}
			else
			{
				arr[i][j] = str[index + K - j - 1];
			}
		}

		index += K;
	}

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < str.length() / K; j++)
		{
			result += arr[j][i];
		}
	}

	cout << result;

	return 0;
}