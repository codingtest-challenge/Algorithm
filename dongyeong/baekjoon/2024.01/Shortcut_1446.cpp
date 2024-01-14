#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	vector<pair<int, int>> v[10001];
	int dist[10001];

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		int a, b, c;
		
		cin >> a >> b >> c;

		if (b > d || b - a < c) continue;

		v[b].push_back({ a,c });
	}

	dist[0] = 0;

	for (int i = 1; i <= d; i++) {
		dist[i] = dist[i - 1] + 1;
		for (int j = 0; j < v[i].size(); j++) {
			dist[i] = min(dist[i], dist[v[i][j].first] + v[i][j].second);
		}

	}

	cout << dist[d];

	return 0;
}