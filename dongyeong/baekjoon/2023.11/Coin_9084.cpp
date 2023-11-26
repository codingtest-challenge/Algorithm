#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T, N, M;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int coin[21] = { 0, };
		int arr[10001] = { 0, };

		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> coin[j];
		}

		cin >> M;

		arr[0] = 1;

		for (int j = 0; j < N; j++) {
			for (int k = coin[j]; k<=M; k++) {
				arr[k] += arr[k - coin[j]];
			}
		}

		cout << arr[M] << "\n";
	}

	return 0;
}