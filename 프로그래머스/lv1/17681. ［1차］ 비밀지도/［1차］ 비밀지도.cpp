#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string str = "";
        int temp = arr1[i] | arr2[i];

        for (int j = n - 1; j >= 0; j--)
        {
            str += to_string((temp >> j) & 1);
        }

        replace(str.begin(), str.end(), '1', '#');
        replace(str.begin(), str.end(), '0', ' ');

        answer.push_back(str);
    }

    return answer;
}