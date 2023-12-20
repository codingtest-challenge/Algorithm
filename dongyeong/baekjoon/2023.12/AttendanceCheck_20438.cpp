#include <iostream>

using namespace std;

int attend[5004];
bool sleep[5004];
int sum[5004];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K, Q, M;
	int S, E;
	int input;

	cin >> N >> K >> Q >> M;

	for (int i = 0; i < K; i++) {
		cin >> input;

		sleep[input] = true;
	}

	for (int i = 0; i < Q; i++) {
		cin >> input;

		if (sleep[input]) continue;

		for (int j = 1; j * input <= N + 2; j++) {
			if (sleep[j * input]) continue;

			attend[j * input] = 1;
		}
	}

	for (int i = 3; i <= N + 2; i++) {
		sum[i] = sum[i - 1] + attend[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> S >> E;

		cout << (E - S + 1) - (sum[E] - sum[S - 1]) << "\n";
	}

	return 0;
}