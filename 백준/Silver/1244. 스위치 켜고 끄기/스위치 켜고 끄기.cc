#include <iostream>

using namespace std;

int switchCount, arr[101], numberStudents, gender, num;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> switchCount;

	for (int i = 1; i <= switchCount; i++)
	{
		cin >> arr[i];
	}

	cin >> numberStudents;

	for (int i = 0; i < numberStudents; i++)
	{
		cin >> gender >> num;

		if (gender == 1)
		{
			for (int i = num; i <= switchCount; i += num)
			{
				arr[i] = arr[i] == 0 ? 1 : 0;
			}
		}
		else if (gender == 2)
		{
			arr[num] = arr[num] == 0 ? 1 : 0;

			for (int i = 1; (num + i <= switchCount && num - i >= 1); i++)
			{
				if (arr[num + i] == arr[num - i])
				{
					arr[num + i] = arr[num + i] == 0 ? 1 : 0;
					arr[num - i] = arr[num - i] == 0 ? 1 : 0;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int i = 1; i <= switchCount; i++)
	{
		if (i % 20 == 0)
		{
			cout << arr[i] << "\n";
		}
		else
		{
			cout << arr[i] << " ";
		}
	}

	return 0;
}