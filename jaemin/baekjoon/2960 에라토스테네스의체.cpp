#include <iostream>
using namespace std;

int main() {
	int n, k;

	int arr[1001] = { 0, };
	int cnt = 0;
	int res = 0;
	bool check = 0;
	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0) continue;
		for (int j = 1; i * j <= n; j++) {
			if (arr[i * j] == 0) {
				arr[i * j] = 1;
				cnt++;
			}

			if (cnt == k) {
				check = 1;
				res = i * j;
				break;
			}
		}
		if (check == 1) break;
	}

	cout << res << endl;

	return 0;
}