#include <iostream>

using namespace std;

int N, L, H, maxL, maxH, endL, leftMaxH, rightMaxH, arr[1001], result;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	while (N--)
	{
		cin >> L >> H;

		arr[L] = H;

		if (maxH < H)
		{
			maxL = L;
			maxH = H;
		}

		if (endL < L)
		{
			endL = L;
		}
	}

	for (int i = 1; i < maxL; i++)
	{
		leftMaxH = max(leftMaxH, arr[i]);
		result += leftMaxH;
	}

	result += maxH;

	for (int i = endL; i > maxL; i--)
	{
		rightMaxH = max(rightMaxH, arr[i]);
		result += rightMaxH;
	}

	cout << result;

	return 0;
}