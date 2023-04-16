#include <iostream>
#include <queue>

using namespace std;

int N, num;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		cin >> num;

		pq.push(num);

		if (pq.size() > N)
		{
			pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}