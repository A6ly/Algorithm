#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> s(nums.begin(), nums.end());
    int ponkemon = s.size();
    int maxV = nums.size() / 2;
    answer = min(ponkemon, maxV);

    return answer;
}