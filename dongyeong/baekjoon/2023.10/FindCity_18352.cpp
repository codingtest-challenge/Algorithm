#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visit [300001];
vector <int> v[300001];
int N, M, K, X, a, b;
int count;

void bfs() {
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> q;

	q.push(X);
	visit[X] = true;


	while (!q.empty()) {
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int now = q.front();
			q.pop();
			if (::count == K) {
				pq.push(now);
			}
			for (int j = 0; j < v[now].size(); j++) {
				if (!visit[v[now][j]]) {
					visit[v[now][j]] = true;
					q.push(v[now][j]);
				}
			}
		}

		::count++;
	}

	if (pq.empty()) cout << "-1\n";
	else {
		while (!pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}
	}
}


int main() {
	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	bfs();

	return 0;
}