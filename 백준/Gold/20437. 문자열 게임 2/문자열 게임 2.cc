#include <iostream>

using namespace std;

int T, K;
string W;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> W >> K;

		int alphabet[26] = { 0 }, num3 = 10000, num4 = -1;

		for (int i = 0; i < W.length(); i++)
		{
			alphabet[W[i] - 'a']++;
		}

		for (int i = 0; i < W.length(); i++)
		{
			if (alphabet[W[i] - 'a'] >= K)
			{
				int cnt = 0;

				for (int j = i; j < W.length(); j++)
				{
					if (W[i] == W[j])
					{
						if (++cnt == K)
						{
							num3 = min(num3, j - i + 1);
							num4 = max(num4, j - i + 1);

							break;
						}
					}
				}
			}
		}

		if (num3 == 10000 && num4 == -1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << num3 << " " << num4 << "\n";
		}
	}

	return 0;
}