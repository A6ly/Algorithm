#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
	vector<int> answer;
	unordered_map<string, int> um;

	for (int i = 0; i < 26; i++)
	{
		char c = 'A' + i;
		string s = string(1, c);
		um[s] = i + 1;
	}

	int index = 27;
	string w = "";

	for (int i = 0; i < msg.length(); i++)
	{
		string wc = w + msg[i];

		if (um.find(wc) != um.end())
		{
			w = wc;
		}
		else
		{
			answer.push_back(um[w]);
			w = msg[i];
			um[wc] = index++;
		}
	}

	answer.push_back(um[w]);

	return answer;
}