#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int k, n, x, sum=0, count=0;
	long long int lo=1, hi, mid;

	cin >> k >> n;
	
	vector<int> v;
	
	for (int i = 0; i < k; i++) {
		cin >> x;
		v.push_back(x);
		sum += x;
	}

	hi = sum/n + 1;

	while (lo!=hi-1) {
		count = 0;
		mid = (hi + lo) / 2;

		for (int i = 0; i < k; i++) {
			count += v[i] / mid;
		}

		if (count >= n) lo = mid;
		else hi = mid;
	}

	cout << lo << "\n";

	return 0;
}