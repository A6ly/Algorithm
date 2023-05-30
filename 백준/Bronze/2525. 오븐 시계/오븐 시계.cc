#include <iostream>

using namespace std;

int H, M, cookingM;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> H >> M >> cookingM;

	int cookingH = cookingM / 60;
	cookingM %= 60;

	H += cookingH;
	M += cookingM;

	if (M >= 60)
	{
		H++;
		M -= 60;
	}

	if (H >= 24)
	{
		H -= 24;
	}

	cout << H << " " << M;
}