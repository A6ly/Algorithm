#include <iostream>
#include <string>

using namespace std;

int A, B, D, cnt;
bool arr[4000001];

void Eratosthenes()
{
    for (int i = 2; i <= 4000000; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 4000000; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= 4000000; j += i)
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

    cin >> A >> B >> D;

    string strD = to_string(D);

    for (int i = A; i <= B; i++)
    {
        if (arr[i])
        {
            string str = to_string(i);

            if (str.find(strD) != string::npos)
            {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}