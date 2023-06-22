#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{
    int answer = 0;
    
    unordered_map<string, int> um;
    
    for (auto cloth : clothes)
    {
        um[cloth[1]]++;
    }
    
    answer++;
    
    for (auto i : um)
    {
        answer *= (i.second + 1);
    }
    
    answer--;
    
    return answer;
}