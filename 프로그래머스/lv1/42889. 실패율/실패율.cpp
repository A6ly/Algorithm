#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, int> a, pair<float, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first > b.first;
    }
}

vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<float, int>> failureRate;
    float size = stages.size();

    for (int i = 1; i <= N; i++)
    {
        float cnt = count(stages.begin(), stages.end(), i);
        failureRate.push_back({ cnt / size, i });
        size -= cnt;
    }

    sort(failureRate.begin(), failureRate.end(), compare);

    for (int i = 0; i < N; i++)
    {
        answer.push_back(failureRate[i].second);
    }

    return answer;
}