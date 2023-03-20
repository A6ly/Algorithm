#include <iostream>

using namespace std;

string str;
int length, result;

bool isPalindrome(int index)
{
    int mid = (length - index) / 2;

    for (int i = 0; i < mid; i++)
    {
        if (str[index + i] != str[length - i - 1])
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

    cin >> str;

    length = str.length();

    for (int i = 0; i < length; i++)
    {
        if (isPalindrome(i))
        {
            result = length + i;

            break;
        }
    }

    cout << result;

    return 0;
}