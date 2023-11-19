#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[300001];
queue<int> q;
int depth[300001];

void dijk(int X) {
	depth[X] = 0;
	q.push(X);

	while (!q.empty()) {
		int current = q.front();

		for (int i = 0; i < v[current].size(); i++) {
			int next = v[current][i];
			if (depth[next] > depth[current]+1) {
				q.push(v[current][i]);
				depth[next] = depth[current]+1;
			}
		}
		q.pop();
	}
}

int main()
{
	int N, M, K, X, A, B;
	bool check = false;

	cin >> N >> M >> K >> X;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		v[A].push_back(B);
	}

	for (int i = 1; i <= N; i++) {
		depth[i] = 400000;
	}

	dijk(X);

	for (int i = 1; i <= N; i++) {
		if (depth[i] == K) {
			cout << i << "\n";
			check = true;
		}
	}
	if (!check) cout << "-1\n";

	return 0;
}