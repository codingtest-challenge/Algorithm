#include <iostream>

using namespace std;

int main()
{
	int T, N, M;
	int result;
	int calc;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		result = 1, calc = 1;
		for (int i = M; i > M - N; i--) {
			result *= i;
			result /= calc++;
		}

		cout << result << "\n";
	}

	return 0;
}