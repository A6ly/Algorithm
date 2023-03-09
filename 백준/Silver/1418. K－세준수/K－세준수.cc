#include <iostream>

using namespace std;

int N, K, cnt;
int arr[100001];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 2; i <= N; i++)
    {
        if (!arr[i])
        {
            for (int j = i; j <= N; j += i)
            {
                arr[j] = max(arr[j], i);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (arr[i] <= K)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}