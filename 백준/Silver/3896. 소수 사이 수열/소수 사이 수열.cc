#include <iostream>

using namespace std;

const int MAX = 1299710;
int T, k, from, to, cnt;
bool isPrime[MAX];

void Eratosthenes()
{
    for (int i = 2; i < MAX; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i < MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Eratosthenes();

    cin >> T;

    while (T--)
    {
        cin >> k;

        cnt = 0;

        if (isPrime[k])
        {
            cout << 0 << "\n";

            continue;
        }

        for (int i = k - 1; i >= 2; i--)
        {
            if (isPrime[i])
            {
                from = i;

                break;
            }
        }

        for (int i = k + 1; i < MAX; i++)
        {
            if (isPrime[i])
            {
                to = i;

                break;
            }
        }

        for (int i = from; i < to; i++)
        {
            if (!isPrime[i])
            {
                cnt++;
            }
        }

        cout << cnt + 1 << "\n";
    }

    return 0;
}