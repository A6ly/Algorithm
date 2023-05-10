#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, x, y, cnt;
vector<int> vec;
stack<int> s;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N;

   for (int i = 0; i < N; i++)
   {
      cin >> x >> y;

      vec.push_back(y);
   }

   for (int i = 0; i < N; i++)
   {
      while (!s.empty() && vec[i] < s.top())
      {
         if (s.top() != 0)
         {
            cnt++;
         }

         s.pop();
      }

      if (s.empty() || vec[i] != s.top())
      {
         s.push(vec[i]);
      }
   }

   while (!s.empty())
   {
      if (s.top() != 0)
      {
         cnt++;
      }

      s.pop();
   }

   cout << cnt;

   return 0;
}