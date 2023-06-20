#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int arr[5000000];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cout << arr[K - 1];

	return 0;
}