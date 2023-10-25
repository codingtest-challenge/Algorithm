#include <iostream>
using namespace std;

int main() {

	long long n;
	long long arr[91] = { 0, };

	arr[0] = 0;
	arr[1] = 1;

	cin >> n;

	for (long long i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n] << endl;

	return 0;

}