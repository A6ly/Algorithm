#include <iostream>
#include <climits>

using namespace std;

const int MAX = 10000001;
long long A, B, cnt;
bool arr[MAX];

void Eratosthenes()
{
    for (int i = 2; i < MAX; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i < MAX; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j < MAX; j += i)
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

    cin >> A >> B;

    for (long long i = 2; i < MAX; i++)
    {
        long long temp = i * i;

        if (temp > B)
        {
            break;
        }

        if (arr[i])
        {
            while (temp <= B)
            {
                if (temp >= A)
                {
                    cnt++;
                }

                temp *= i;

                if (temp % i != 0)
                {
                    break;
                }
            }
        }
    }

    cout << cnt;

    return 0;
}