#include <iostream>
#include <string>

using namespace std;

string str;
int index, cnt;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;

	while (true)
	{
		index++;

		string temp = to_string(index);

		for (int i = 0; i < temp.length(); i++)
		{
			if (temp.at(i) == str.at(cnt))
			{
				cnt++;
			}

			if (cnt == str.length())
			{
				cout << index;

				return 0;
			}
		}
	}

	return 0;
}