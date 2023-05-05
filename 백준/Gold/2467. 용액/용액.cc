#include <iostream>

using namespace std;

int N, arr[100000], sum = 2000000001;
pair<int, int> result;

void TwoPointer()
{
	int left = 0, right = N - 1;

	while (left < right)
	{
		int temp = arr[left] + arr[right];

		if (abs(temp) < abs(sum))
		{
			sum = temp;
			result.first = arr[left];
			result.second = arr[right];
		}

		if (temp == 0)
		{
			break;
		}
		else if (temp < 0)
		{
			left++;
		}
		else if (temp > 0)
		{
			right--;
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	TwoPointer();

	cout << result.first << " " << result.second;

	return 0;
}