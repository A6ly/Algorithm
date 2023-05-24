#include <iostream>

using namespace std;

int K, N, M, total;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> N >> M;

	total = K * N;

	if (total <= M)
	{
		cout << 0;
	}
	else
	{
		cout << total - M;
	}

	return 0;
}