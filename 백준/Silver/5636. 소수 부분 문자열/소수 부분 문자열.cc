#include <iostream>
#include <string>

using namespace std;

const int MAX = 100001;
int result;
bool isPrime[MAX];
string str;

void Eratosthenes()
{
	for (int i = 2; i < MAX; i++)
	{
		isPrime[i] = true;
	}

	for (int i = 2; i * i < MAX; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Eratosthenes();

	while (true)
	{
		cin >> str;

		if (str == "0")
		{
			break;
		}

		for (int i = 0; i < str.length(); i++)
		{
			for (int j = 1; j < 6; j++)
			{
				string temp = str.substr(i, j);
				int num = stoi(temp);

				if (isPrime[num])
				{
					result = max(result, num);
				}
			}
		}

		cout << result << "\n";

		result = 0;
	}

	return 0;
}