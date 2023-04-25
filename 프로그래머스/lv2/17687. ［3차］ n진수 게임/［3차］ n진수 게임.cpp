#include <string>

using namespace std;

string solution(int n, int t, int m, int p)
{
	string answer = "";
	string str = "0";

	for (int i = 1; str.length() < t * m; i++)
	{
		int num = i;
		int index = 0;
		char array[18];

		while (num > 0)
		{
			array[index] = num % n;

			if (array[index] < 10)
			{
				array[index] = array[index] + '0';
			}
			else
			{
				array[index] = array[index] - 10 + 'A';
			}

			num = num / n;
			index++;
		}

		for (int j = index - 1; j >= 0; j--)
		{
			str += array[j];
		}
	}

	for (int i = p - 1; answer.length() < t; i += m)
	{
		answer += str[i];
	}

	return answer;
}