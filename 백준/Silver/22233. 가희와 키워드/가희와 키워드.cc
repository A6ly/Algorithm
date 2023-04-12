#include <iostream>
#include <unordered_set>

using namespace std;

int N, M, pos, endPos;
bool isExit;
string str, keyword;
unordered_set<string> keywords;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> str;

		keywords.insert(str);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;

		pos = 0;

		while (pos != string::npos)
		{
			endPos = str.find(',', pos);

			if (endPos == string::npos)
			{
				keyword = str.substr(pos);

				pos = string::npos;
			}
			else
			{
				keyword = str.substr(pos, endPos - pos);

				pos = endPos + 1;
			}

			if (keywords.find(keyword) != keywords.end())
			{
				keywords.erase(keyword);
			}
		}

		cout << keywords.size() << "\n";
	}

	return 0;
}