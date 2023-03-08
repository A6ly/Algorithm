#include <string>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0;

    for (int i = 0; i <= t.length() - p.length(); i++)
    {
        if (stol(p) >= stol(t.substr(i, p.length())))
        {
            answer++;
        }
    }

    return answer;
}