#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[50001] = { 0, };

	int n;
	cin >> n;

	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i-1] + 1;
		for (int j = 2; j * j <= i; j++) {
			arr[i] = min(arr[i], arr[i - j * j]+1);
		}
	}

	cout << arr[n] << endl;

	

	return 0;
}