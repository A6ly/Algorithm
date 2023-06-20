#include <iostream>

using namespace std;

int N, M, K, i, j, x, y, arr[301][301];

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N >> M;

   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= M; j++)
      {
         cin >> arr[i][j];
      }
   }

   cin >> K;

   while (K--)
   {
      cin >> i >> j >> x >> y;

      int sum = 0;

      for (int a = i; a <= x; a++)
      {
         for (int b = j; b <= y; b++)
         {
            sum += arr[a][b];
         }
      }

      cout << sum << "\n";
   }

   return 0;
}