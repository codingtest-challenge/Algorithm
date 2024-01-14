#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int length(int x, int y, int a, int b) {
	return abs(a - x) + abs(b - y);
}


int main() {
	int t, n;

	cin >> t;

	while (t--) {
		queue<pair<int, int>> q;
		pair<int, int> start, end;
		bool visit[10001] = { false, };
		bool tf = false;

		cin >> n;
		vector<pair<int, int>> v(n, { 0,0 });

		cin >> start.first >> start.second;

		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
		}

		cin >> end.first >> end.second;

		q.push({ start.first, start.second });

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < v.size(); i++) {
				if (length(x, y, v[i].first, v[i].second) <= 1000) {
					if (!visit[i]) {
						visit[i] = true;
						q.push({ v[i].first, v[i].second });
					}
				}
			}
			if (length(x, y, end.first, end.second) <= 1000) {
				tf = true;
				break;
			}
		}

		if (tf) cout << "happy\n";
		else cout << "sad\n";
	}

	cout << "\n";

	return 0;
}