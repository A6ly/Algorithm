#include <iostream>

using namespace std;

int A, B, result;
bool arr[100001];

void Eratosthenes()
{
    for (int i = 2; i <= 100000; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 100000; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= 100000; j += i)
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

    for (int i = A; i <= B; i++)
    {
        int temp = i;
        int cnt = 0;

        for (int j = 2; j <= i; j++)
        {
            if (temp == 1)
            {
                break;
            }

            if (arr[j])
            {
                while (temp % j == 0)
                {
                    temp /= j;
                    cnt++;
                }
            }
        }

        if (arr[cnt])
        {
            result++;
        }
    }

    cout << result;

    return 0;
}