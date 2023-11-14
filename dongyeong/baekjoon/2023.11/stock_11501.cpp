#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T, N;
	vector <int> v;

	cin >> T;

	for (int i = 0; i < T; i++) {
		long long int result=0;
		int maximum = 0;

		cin >> N;
		for (int j = 0; j < N; j++) {
			int input;

			cin >> input;
			v.push_back(input);
		}

		for (int j = N-1; j >= 0; j--) {
			maximum = max(maximum, v[j]);
			result += maximum - v[j];
		}

		cout << result << "\n";
		v.clear();
	}

	return 0;
}