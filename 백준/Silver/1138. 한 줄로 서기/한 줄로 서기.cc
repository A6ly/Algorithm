#include <iostream>
#include <vector>

using namespace std;

int N, arr[11];
vector<int> vec;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}

	for (int i = N; i > 0; i--)
	{
		vec.insert(vec.begin() + arr[i], i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}