#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A[1001] = { 0, };
	int arr[1001] = { 0, };
	int N, length = 1;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		arr[i] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) arr[i] = max(arr[i], arr[j]+1);
		}
		if (arr[i] > length) length = arr[i];
	}

	cout << length << "\n";

	return 0;
}