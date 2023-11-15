#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> weight[20001];
int dist[20001];

void dijk(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int current = pq.top().second;
		int cDistance = pq.top().first;

		pq.pop();

		if (dist[current] < cDistance) continue;

		for (int i = 0; i < weight[current].size(); i++) {
			int next = weight[current][i].second;
			int nDistance = cDistance + weight[current][i].first;

			if (dist[next] > nDistance) {
				dist[next] = nDistance;

				pq.push({ nDistance, next });
			}
		}
	}
}

int main()
{
	int V, E, start;
	int from, to, input;

	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) {
		dist[i] = 300000;
	}

	for (int i = 0; i < E; i++) {
		cin >> from >> to >> input;
		
		weight[from].push_back({ input, to });
	}

	dijk(start);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == 300000) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}