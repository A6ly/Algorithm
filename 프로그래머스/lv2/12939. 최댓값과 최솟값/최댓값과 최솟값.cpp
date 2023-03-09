#include <string>

using namespace std;

string solution(string s) 
{
    string answer = "", str = "";
    int min = INT16_MAX, max = INT16_MIN, temp = 0;

    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || i == s.length())
        {
            temp = stoi(str);
            str = "";

            if (min > temp)
            {
                min = temp;
            }

            if (max < temp)
            {
                max = temp;
            }
        }
        else
        {
            str += s[i];
        }
    }

    answer = to_string(min) + ' ' + to_string(max);

    return answer;
}