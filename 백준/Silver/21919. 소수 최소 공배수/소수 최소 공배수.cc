#include <iostream>

using namespace std;

int N, num;
long long result = 1;
bool arr[1000001];

void Eratosthenes()
{
    for (int i = 2; i <= 1000000; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 1000000; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                arr[j] = false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Eratosthenes();

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (arr[num] && result % num != 0)
        {
            result *= num;
        }
    }

    if (result != 1)
    {
        cout << result;
    }
    else
    {
        cout << -1;
    }

    return 0;
}