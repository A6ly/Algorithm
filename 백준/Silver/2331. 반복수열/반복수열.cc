#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 300001;
int A, P, sum, result;
vector<int> visit(MAX);

void DFS(int num)
{
	visit[num]++;

	if (visit[num] > 2)
	{
		return;
	}

	sum = 0;

	while (num)
	{
		sum += pow((num % 10), P);
		num /= 10;
	}

	DFS(sum);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> P;

	DFS(A);

	for (int i = 0; i < MAX; i++)
	{
		if (visit[i] == 1)
		{
			result++;
		}
	}

	cout << result;

	return 0;
}