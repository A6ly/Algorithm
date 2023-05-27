#include <iostream>
#include <set>

using namespace std;

int T, k, n;
char c;
multiset<int> ms;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> T;

   while (T--)
   {
      cin >> k;

      for (int i = 0; i < k; i++)
      {
         cin >> c >> n;

         if (c == 'I')
         {
            ms.insert(n);
         }
         else if (c == 'D')
         {
            if (!ms.empty() && n == 1)
            {
               auto iter = ms.end();
               iter--;
               ms.erase(iter);
            }
            else if (!ms.empty() && n == -1)
            {
               ms.erase(ms.begin());
            }
         }
      }

      if (ms.empty())
      {
         cout << "EMPTY\n";
      }
      else
      {
         auto endIter = ms.end();
         endIter--;
         cout << *endIter << ' ' << *ms.begin() << "\n";

         ms.clear();
      }
   }

   return 0;
}