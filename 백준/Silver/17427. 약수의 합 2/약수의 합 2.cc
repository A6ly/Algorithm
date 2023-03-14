#include <iostream>

using namespace std;

int N;
long long result;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        result += (N / i) * i;
    }

    cout << result;

    return 0;
}