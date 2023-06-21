#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2000000;
int T;
long long A, B, sum;
bool isPrime[MAX + 1];
vector<int> vec;

void Eratosthenes()
{
	for (int i = 2; i <= MAX; i++)
	{
		isPrime[i] = true;
	}

	for (int i = 2; i <= MAX; i++)
	{
		if (isPrime[i])
		{
			vec.push_back(i);

			for (int j = i * 2; j <= MAX; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}

bool CheckPrime(long long num)
{
	if (num <= MAX)
	{
		return isPrime[num];
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (num % vec[i] == 0)
			{
				return false;
			}
		}

		return true;
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	Eratosthenes();

	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		sum = A + B;

		if (sum == 2)
		{
			cout << "NO\n";
		}
		else if (sum % 2 == 0)
		{
			cout << "YES\n";
		}
		else
		{
			if (CheckPrime(sum - 2))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}