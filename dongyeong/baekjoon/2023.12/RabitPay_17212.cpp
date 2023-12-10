#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
	int N;

	arr[1] = arr[2] = arr[5] = arr[7] = 1;
	arr[3] = arr[4] = arr[6] = 2;

	cin >> N;
	
	if(N > 7) {
		for (int i = 8; i <= N; i++) {
			arr[i] = min(arr[i - 1] + 1, min(arr[i - 2] + 1, min(arr[i - 5] + 1, arr[i - 7] + 1)));
		}
	}

	cout << arr[N] << "\n";


	return 0;
}