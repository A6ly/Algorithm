#include <iostream>
#include <map>

using namespace std;

int N, K, num, pSum[200001];
long long cnt;
map<int, long long> m;

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N >> K;

   m[0] = 1;

   for (int i = 1; i <= N; i++)
   {
      cin >> num;

      pSum[i] = pSum[i - 1] + num;

      cnt += m[pSum[i] - K];

      m[pSum[i]]++;
   }

   cout << cnt;

   return 0;
}