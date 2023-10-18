#include<iostream>

using namespace std;

int main()
{
	int n, x;
	int max = 0;

	cin >> n;

	int* arr = new int[n]();

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (i == 0) cout << 0 << endl;
			else {
				for (int j = 0; j < i; j++) {
					if (arr[j] > max) max = arr[j];
				}
				for (int j = 0; j < i; j++) {
					if (arr[j] == max) arr[j] = 0;
				}
				cout << max << endl;
				max = 0;
			}
		}
		else if (x > 0) {
			arr[i]=x;
		}
	}

	delete[] arr;

	return 0;
}