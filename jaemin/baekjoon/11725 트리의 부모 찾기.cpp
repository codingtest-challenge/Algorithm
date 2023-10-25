// 11725 트리의 부모 찾기

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];

bool dfscheck[100001];
int res[100001];

void dfs(int s) {
	dfscheck[s] = true;

	for (int i = 0; i < v[s].size(); i++) {
		int nxt = v[s][i];
		if (dfscheck[nxt] == 0) {
			res[nxt] = s;
			dfs(nxt);
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << res[i] << "\n";
	}


	return 0;

}