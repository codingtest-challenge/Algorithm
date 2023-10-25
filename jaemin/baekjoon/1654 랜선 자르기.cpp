#include <iostream>
#include <vector>
using namespace std;

int main() {

	long long n, k;
	long long m = 0;
	vector<int> v;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		v.push_back(x);

		m = max(m, x);
	}

	while (1) {
		long long count = 0;

		if (m == 0) break;
		
		for (long long i = 0; i < n; i++) {
			count += v[i] / m;
		}

		if (count == k) break;

		m /= 2;
	}

	cout << m << "\n";

	return 0;
}