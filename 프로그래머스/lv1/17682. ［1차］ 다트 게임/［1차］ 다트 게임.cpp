#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult)
{
    int answer = 0, cnt = 0, num = 0;
    vector<int> vec;

    for (int i = 0; i < dartResult.length(); i++)
    {
        if (isdigit(dartResult[i + 1]) || i == dartResult.length() - 1)
        {
            if (isdigit(dartResult[i - cnt + 1]))
            {
                num = stoi(dartResult.substr(i - cnt, 2));

                if (dartResult[i - cnt + 2] == 'D')
                {
                    num = pow(num, 2);
                }
                else if (dartResult[i - cnt + 2] == 'T')
                {
                    num = pow(num, 3);
                }
            }
            else
            {
                num = dartResult[i - cnt] - '0';

                if (dartResult[i - cnt + 1] == 'D')
                {
                    num = pow(num, 2);
                }
                else if (dartResult[i - cnt + 1] == 'T')
                {
                    num = pow(num, 3);
                }
            }

            if (dartResult[i] == '*')
            {
                if (vec.empty())
                {
                    num *= 2;
                }
                else
                {
                    num *= 2;
                    int temp = vec.back() * 2;
                    vec.pop_back();
                    vec.push_back(temp);
                }
            }
            else if (dartResult[i] == '#')
            {
                num *= -1;
            }
            
            vec.push_back(num);
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        answer += vec[i];
    }

    return answer;
}