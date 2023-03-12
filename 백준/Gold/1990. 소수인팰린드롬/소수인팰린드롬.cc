#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int a, b;

bool IsPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        if (i > 9989899)
        {
            break;
        }

        string str1 = to_string(i), str2 = to_string(i);
        reverse(str2.begin(), str2.end());

        if (str1 == str2 && IsPrime(i))
        {
            cout << i << "\n";
        }
    }

    cout << -1;

    return 0;
}