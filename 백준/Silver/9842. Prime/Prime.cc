#include <iostream>

using namespace std;

const int MAX = 104744;
int n, cnt;
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

    cin >> n;

    for (int i = 2; i < MAX; i++)
    {
        if (isPrime[i])
        {
            cnt++;

            if (cnt == n)
            {
                cout << i;

                break;
            }
        }
    }

    return 0;
}