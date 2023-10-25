#include <iostream>
#include <queue>

using namespace std;

int count = 0;
queue <int> q[501];
bool check[501] = { false, };


void invite() {
	check[1] = true;
	while (!q[1].empty()) {
		int temp = q[1].front();
		q[0].push(temp);
		::count++;
		check[temp] = true;
		q[1].pop();
	}

	while (!q[0].empty()) {
		int temp = q[0].front();
		while (!q[temp].empty()) {
			if (!check[q[temp].front()]) {
				check[q[temp].front()] = true;
				::count++;
			}
			q[temp].pop();
		}
		q[0].pop();
	}
}

int main()
{
	int n, m, a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		q[a].push(b);
		q[b].push(a);
	}

	invite();

	cout << ::count << "\n";

	return 0;
}