#include <iostream>

using namespace std;

const int MAX = 100001;
int T, k, result;
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
        result = MAX;

        cin >> k;

        for (int i = 2; i < MAX; i++)
        {
            if (isPrime[i])
            {
                for (int j = 2; j < MAX; j++)
                {
                    if (isPrime[j] && i != j)
                    {
                        if (i * j >= k)
                        {
                            result = min(result, i * j);

                            break;
                        }
                    }
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}