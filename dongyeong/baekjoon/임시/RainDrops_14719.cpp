#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int H, W;
	int arr[501] = { 0, };
	int sum = 0;

	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < W; i++) {
		int l = 0, r = 0;

		for (int j = 0; j < i; j++) {
			l = max(l, arr[j]);
		}
		for (int j = i + 1; j < W; j++) {
			r = max(r, arr[j]);
		}

		sum += max(0, min(l, r) - arr[i]);
	}


	cout << sum << "\n";

	return 0;
}