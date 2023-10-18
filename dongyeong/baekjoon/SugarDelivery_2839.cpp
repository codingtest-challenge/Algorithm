#include <iostream>

using namespace std;

int main()
{
	int N;

	int arr[5001] = {0, };

	arr[0] = -1;
	arr[1] = -1;
	arr[2] = -1;
	arr[3] = 1;
	arr[4] = -1;
	arr[5] = 1;
	arr[6] = 2;
	arr[7] = -1;

	cin >> N;

	if (N < 8) {
		cout << arr[N] << "\n";
	}
	else {
		for (int i = 8; i <= N; i++) {
			if (arr[i - 5] != -1) {
				arr[i] = arr[i - 5] + 1;
			}
			else if (arr[i - 3] != -1) {
				arr[i] = arr[i - 3] + 1;
			}
			else arr[i] = -1;
		}

		cout << arr[N] << "\n";
	}


	return 0;
}