#include <iostream>

using namespace std;

const int MAX = 1001;
int N, K, nation, gold[MAX], silver[MAX], bronze[MAX], result = 1;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> nation;
		cin >> gold[nation] >> silver[nation] >> bronze[nation];
	}

	for (int i = 1; i <= N; i++)
	{
		if (gold[i] > gold[K])
		{
			result++;
		}
		else if (gold[i] == gold[K])
		{
			if (silver[i] > silver[K])
			{
				result++;
			}
			else if (silver[i] == silver[K])
			{
				if (bronze[i] > bronze[K])
				{
					result++;
				}
			}
		}
	}

	cout << result;

	return 0;
}