#include <iostream>

using namespace std;

int N, cnt, original[26];
string str;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	cnt = N - 1;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		original[str[i] - 'A']++;
	}

	for (int i = 1; i < N; i++)
	{
		cin >> str;

		int temp[26] = { 0, };

		for (int j = 0; j < str.length(); j++)
		{
			temp[str[j] - 'A']++;
		}

		int first = -1, diff = 0;

		for (int j = 0; j < 26; j++)
		{
			if (original[j] != temp[j])
			{
				if (first == -1)
				{
					first = j;
				}

				if (abs(original[j] - temp[j]) > 1)
				{
					cnt--;

					break;
				}
				else
				{
					diff++;

					if (diff == 2)
					{
						if (original[first] + original[j] != temp[first] + temp[j])
						{
							cnt--;

							break;
						}
					}
					else if (diff > 2)
					{
						cnt--;

						break;
					}
				}
			}
		}
	}

	cout << cnt;

	return 0;
}