#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, X[1000000];
vector<int> vec;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N;

   for (int i = 0; i < N; i++)
   {
      cin >> X[i];

      vec.push_back(X[i]);
   }

   sort(vec.begin(), vec.end());
   vec.erase(unique(vec.begin(), vec.end()), vec.end());

   for (int i = 0; i < N; i++)
   {
      cout << lower_bound(vec.begin(), vec.end(), X[i]) - vec.begin() << " ";
   }

   return 0;
}