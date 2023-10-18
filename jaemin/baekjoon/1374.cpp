#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int main() {
	int n;
	priority_queue<int, vector<int>, greater<int>> pq;
	int cnt = 0;

	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int r, s, e;
		cin >> r >> s >> e;
		v.push_back({ s, e });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (pq.empty()) {
			pq.push(v[i].second);
		}
		else {
			if (pq.top() <= v[i].first) {
				pq.pop();
				pq.push(v[i].second);
			}
			else {
				pq.push(v[i].second);
			}

		}
	}

	cout << pq.size() << "\n";

	return 0;
}