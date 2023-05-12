#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int T, N;
vector<string> vec;

void DFS(int num, int result, string str)
{
   if (num == N + 1)
   {
      if (result == 0)
      {
         vec.push_back(str.substr(1));
      }

      return;
   }

   DFS(num + 1, num + result, str + '+' + to_string(num));

   if (num <= N - 1)
   {
      DFS(num + 2, result + (num * 10 + num + 1), str + '+' + to_string(num) + ' ' + to_string(num + 1));
   }

   if (num == 1)
   {
      return;
   }

   DFS(num + 1, result - num, str + '-' + to_string(num));

   if (num <= N - 1)
   {
      DFS(num + 2, result - (num * 10 + num + 1), str + '-' + to_string(num) + ' ' + to_string(num + 1));
   }
}

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> T;

   while (T--)
   {
      cin >> N;

      DFS(1, 0, "");

      sort(vec.begin(), vec.end());

      for (int i = 0; i < vec.size(); i++)
      {
         cout << vec[i] << "\n";
      }

      cout << "\n";

      vec.clear();
   }

   return 0;
}