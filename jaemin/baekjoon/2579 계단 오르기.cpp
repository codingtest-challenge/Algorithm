#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;

	vector<int> v;
	vector<int> res;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	res.push_back(v[0]);
	res.push_back(v[0] + v[1]);
	res.push_back(max(v[0] + v[2], v[1] + v[2]));


	for (int i = 3; i < n; i++) {
		res.push_back(max(res[i - 3] + v[i - 1] + v[i], res[i - 2] + v[i]));
	}

	cout << res[n-1] << endl;

	return 0;
}