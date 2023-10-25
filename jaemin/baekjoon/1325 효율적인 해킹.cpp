#include <iostream>
#include <vector>
using namespace std;


vector<int> arr[10001];
int c = 0;

void dfs(int f, bool *dfscheck) {
	dfscheck[f] = true;
	c++;

	for (int i = 0; i < arr[f].size(); i++) {
		int x = arr[f][i];
		if (dfscheck[x] == 0) {
			dfs(x, dfscheck);
		}
	}
}

int main() {
	int n, int m;
	int cnt = 10001;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;

		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		bool dfscheck[10001] = { 0, };
		c = 0;

		cnt = min(c, cnt);

	}



	return 0;
}