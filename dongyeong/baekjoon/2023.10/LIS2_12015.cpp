#include <iostream>
#include <algorithm>

using namespace std;

int A[1000001];
int arr[1000001];

int bSearch(int start, int end, int input) {
	int mid;

	while (start < end) {
		mid = (start + end) / 2;

		if (arr[mid] < input) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}

	return end;
}

int main() {
	int N, length = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	arr[0] = A[0];

	for(int i = 1; i < N; i++) {
		if (arr[length-1] < A[i]) {
			arr[length] = A[i];
			length++;
		}
		else {
			int pos = bSearch(0, length, A[i]);
			arr[pos] = A[i];
		}
	}

	cout << length << "\n";

	return 0;
}