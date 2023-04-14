#include <iostream>
#include <vector>

using namespace std;

int T, N, largest;
long long profit;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N;

		vector<int> stock;

		largest = 0;
		profit = 0;

		for (int i = 0; i < N; i++)
		{
			int num;

			cin >> num;

			stock.push_back(num);
		}

		for (int i = N - 1; i >= 0; i--)
		{
			if (stock[i] > largest)
			{
				largest = stock[i];
			}
			else
			{
				profit += largest - stock[i];
			}
		}

		cout << profit << "\n";
	}

	return 0;
}