#include <iostream>

using namespace std;

const int MAX = 100000;
int N, M, attackPower[MAX];
string title[MAX];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> title[i] >> attackPower[i];
	}

	for (int i = 0; i < M; i++)
	{
		int num;

		cin >> num;

		cout << title[lower_bound(attackPower, attackPower + N, num) - attackPower] << "\n";
	}

	return 0;
}