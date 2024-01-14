#include <iostream>

using namespace std;

int k;
int arr[50];
int result[6];

void lotto(int x, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << " ";
		}
		cout << "\n";
	}
	else {
		for (int i = x + 1; i < k-5+count; i++) {
			result[count] = arr[i];
			lotto(i, count+1);
		}
	}
}

int main()
{
	while (true) {
		cin >> k;

		if (k == 0) break;

		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < k - 5; i++) {
			result[0] = arr[i];
			lotto(i, 1);
		}
		cout << "\n";
	}

	return 0;
}