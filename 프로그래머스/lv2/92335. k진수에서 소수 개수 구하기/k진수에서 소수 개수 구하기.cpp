#include <string>
#include <cmath>

using namespace std;

bool IsPrime(long long num)
{
	if (num <= 1)
	{
		return false;
	}

	for (long long i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(int n, int k)
{
	int answer = 0;
	string str = "";

	while (n > 0)
	{
		str = to_string(n % k) + str;
		n /= k;
	}

	int pos = 0;

	while (!str.empty())
	{
		if ((pos = str.find('0')) != string::npos)
		{
			if (pos == 0)
			{
				str.erase(0, 1);
			}
			else
			{
				string temp = str.substr(0, pos);

				if (!temp.empty())
				{
					if (IsPrime(stoll(temp)))
					{
						answer++;
					}
				}

				str.erase(0, pos + 1);
			}
		}
		else
		{
			if (IsPrime(stoll(str)))
			{
				answer++;
			}

			break;
		}
	}

	return answer;
}