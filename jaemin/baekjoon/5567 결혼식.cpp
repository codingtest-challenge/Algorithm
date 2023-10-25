// 5567 °áÈ¥½Ä

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[501];
queue<int> q;
bool visited[501];

int bfs() {
	int cnt = 0;
	visited[1] = true;
	
	for (int i = 0; i < v[1].size(); i++) {
		q.push(v[1][i]);
		visited[v[1][i]] = true;
		cnt++;
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int nxt = v[x][i];
			if (!visited[nxt]) {
				visited[nxt] = true;
				cnt++;
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

	
	cout << bfs() << endl;
	return 0;
}