// 5567 °áÈ¥½Ä
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];
queue<int> q;
int visited[501];

int bfs(int x) {
	visited[x] = true;
	q.push(x);
	int cnt = 0;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nxt = v[x][i];
			if (!visited[nxt]) {
				visited[nxt] = visited[x] + 1;
				if (visited[nxt] < 4) cnt++;
				q.push(nxt);
			}
		}
	}


	return cnt;
}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	cout << bfs(1) << endl;

	return 0;
}