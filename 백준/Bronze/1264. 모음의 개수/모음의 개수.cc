#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;
char vowel[5] = { 'a', 'e', 'i', 'o' , 'u' };

int main()
{
	while (true)
	{
		int cnt = 0;

		getline(cin, str);

		if (str == "#")
		{
			return 0;
		}

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}

		for (int i = 0; i < 5; i++)
		{
			cnt += count(str.begin(), str.end(), vowel[i]);
		}

		cout << cnt << "\n";
	}

	return 0;
}