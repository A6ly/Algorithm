#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Comp(string a, string b)
{
	return a + b > b + a;
}

string solution(vector<int> numbers)
{
	string answer = "";
	vector<string> vec;

	for (int i = 0; i < numbers.size(); i++)
	{
		vec.push_back(to_string(numbers[i]));
	}

	sort(vec.begin(), vec.end(), Comp);

	for (int i = 0; i < vec.size(); i++)
	{
		answer += vec[i];
	}

	if (answer[0] == '0')
	{
		answer = "0";
	}

	return answer;
}