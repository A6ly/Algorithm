#include <iostream>

using namespace std;

const int MAX = 1000001;
int T, N;
long long arr[MAX];

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;

    for (int i = 1; i < MAX; i++)
    {
        for (int j = 1; i * j < MAX; j++)
        {
            arr[i * j] += i;
        }

        arr[i] += arr[i - 1];
    }

    while (T--)
    {
        cin >> N;

        cout << arr[N] << "\n";
    }

    return 0;
}