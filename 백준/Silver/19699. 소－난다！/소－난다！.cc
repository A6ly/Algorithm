#include <iostream>
#include <set>

using namespace std;

int N, M, H[9];
bool arr[9001];
set<int> result;

void Eratosthenes()
{
    for (int i = 2; i <= 9000; i++)
    {
        arr[i] = true;
    }

    for (int i = 2; i * i <= 9000; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= 9000; j += i)
            {
                arr[j] = false;
            }
        }
    }
}

void DFS(int idx, int cnt, int sum)
{
    if (cnt == M)
    {
        if (arr[sum])
        {
            result.insert(sum);
        }

        return;
    }

    for (int i = idx; i < N; i++)
    {
        DFS(i + 1, cnt + 1, sum + H[i]);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    Eratosthenes();

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }

    DFS(0, 0, 0);

    if (!result.empty())
    {
        for (auto i : result)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << -1;
    }

    return 0;
}