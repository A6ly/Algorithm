#include <string>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0, length = p.length();

    for (int i = 0; i <= t.length() - length; i++)
    {
        if (stol(p) >= stol(t.substr(i, length)))
        {
            answer++;
        }
    }

    return answer;
}