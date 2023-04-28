#include <iostream>
#include <queue>

using namespace std;

int N, num;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N--)
	{
		cin >> num;

		if (max_heap.empty())
		{
			max_heap.push(num);

			cout << num << "\n";

			continue;
		}

		if (max_heap.size() == min_heap.size())
		{
			max_heap.push(num);
		}
		else
		{
			min_heap.push(num);
		}

		if (max_heap.top() > min_heap.top())
		{
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}

		cout << max_heap.top() << "\n";
	}

	return 0;
}