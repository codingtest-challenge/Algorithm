#include <iostream>

using namespace std;

int main()
{
	int T, n;
	int arr[12] = { 0, };

	cin >> T;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++) {
		arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
	}

	for (int i = 0; i < T; i++) {
		cin >> n;

		cout << arr[n] << "\n";
	}

	return 0;
}