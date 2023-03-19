#include <iostream>

using namespace std;

string name, result;
int alphabet[26], cnt;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> name;

    for (int i = 0; i < name.length(); i++)
    {
        alphabet[name[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2)
        {
            cnt++;
        }

        if (cnt > 1)
        {
            cout << "I'm Sorry Hansoo";

            return 0;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < alphabet[i] / 2; j++)
        {
            result += i + 'A';
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2)
        {
            result += i + 'A';
        }
    }

    for (int i = 25; i > -1; i--)
    {
        for (int j = 0; j < alphabet[i] / 2; j++)
        {
            result += i + 'A';
        }
    }

    cout << result;

    return 0;
}