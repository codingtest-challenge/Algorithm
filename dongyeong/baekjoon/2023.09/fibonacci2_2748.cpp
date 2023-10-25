#include <iostream>

using namespace std;

long long int arr[91] = { 0, };

int main()
{
	int n;

	cin >> n;

	if (n == 0) {
		cout << "0\n";
	}
	else if (n == 1) {
		cout << "1\n";
	}
	else if (n > 1 && n <= 90) {
		arr[1] = 1;
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 2] + arr[i - 1];
		}

		cout << arr[n] << "\n";
	}


	return 0;
}