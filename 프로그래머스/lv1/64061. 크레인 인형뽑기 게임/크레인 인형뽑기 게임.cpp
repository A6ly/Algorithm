#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;
	vector<int> basket, result;

	for (int i = 0; i < moves.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			int doll = board[j][moves[i] - 1];

			if (!doll)
			{
				continue;
			}

			board[j][moves[i] - 1] = 0;

			if (!result.empty())
			{
				basket.push_back(doll);

				if (result.back() == doll)
				{
					result.pop_back();
				}
				else
				{
					result.push_back(doll);
				}

				break;
			}
			else
			{
				basket.push_back(doll);
				result.push_back(doll);

				break;
			}
		}
	}

	answer = basket.size() - result.size();

	return answer;
}