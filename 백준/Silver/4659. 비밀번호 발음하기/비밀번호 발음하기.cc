#include <iostream>

using namespace std;

string str, vowel = "aeiou";

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		int v = 0, c = 0;
		bool isAcceptable = true;

		cin >> str;

		if (str == "end")
		{
			break;
		}

		if (str.find("a") != string::npos || str.find("e") != string::npos || str.find("i") != string::npos || str.find("o") != string::npos || str.find("u") != string::npos)
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (vowel.find(str[i]) != string::npos)
				{
					v++;
					c = 0;
				}
				else
				{
					c++;
					v = 0;
				}

				if (v >= 3 || c >= 3)
				{
					isAcceptable = false;

					break;
				}

				if (i > 0 && str[i] == str[i - 1] && !(str[i] == 'e' || str[i] == 'o'))
				{
					isAcceptable = false;

					break;
				}
			}
		}
		else
		{
			isAcceptable = false;
		}

		if (isAcceptable)
		{
			cout << "<" << str << "> " << "is acceptable.\n";
		}
		else
		{
			cout << "<" << str << "> " << "is not acceptable.\n";
		}
	}

	return 0;
}