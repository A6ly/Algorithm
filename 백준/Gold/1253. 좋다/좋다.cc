#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, cnt;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N;

   vector<int> vec(N);

   for (int i = 0; i < N; i++)
   {
      cin >> vec[i];
   }

   sort(vec.begin(), vec.end());

   for (int i = 0; i < N; i++)
   {
      int l = 0, r = N - 1;

      while (l < r)
      {
         if (l == i)
         {
            l++;
            continue;
         }
         else if (r == i)
         {
            r--;
            continue;
         }
         else if (vec[i] > vec[l] + vec[r])
         {
            l++;
         }
         else if (vec[i] < vec[l] + vec[r])
         {
            r--;
         }
         else if (vec[i] == vec[l] + vec[r])
         {
            cnt++;

            break;
         }
      }
   }

   cout << cnt;

   return 0;
}