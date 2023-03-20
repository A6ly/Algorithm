#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id)
{
	string answer = "";

	for (int i = 0; i < new_id.length(); i++)
	{
		new_id[i] = tolower(new_id[i]);
	}

	new_id = regex_replace(new_id, regex("[^a-z0-9-_.]+"), "");
	new_id = regex_replace(new_id, regex("[.]{2,}"), ".");

	if (new_id[0] == '.')
	{
		new_id.erase(0, 1);
	}

	if (new_id[new_id.length() - 1] == '.')
	{
		new_id.erase(new_id.length() - 1, 1);
	}

	if (new_id == "")
	{
		new_id = "a";
	}

	if (new_id.length() >= 16)
	{
		new_id = new_id.substr(0, 15);
	}

	if (new_id[new_id.length() - 1] == '.')
	{
		new_id.erase(new_id.length() - 1, 1);
	}

	if (new_id.length() <= 2)
	{
		while (new_id.length() != 3)
		{
			new_id += new_id[new_id.length() - 1];
		}
	}

	answer = new_id;

	return answer;
}