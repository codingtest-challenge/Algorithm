#include <iostream>
#include <queue>

using namespace std;

int arr[100001];

int main()
{
	int N;
	int num, start, end, count = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	priority_queue <int, vector<int>, greater<int>> lt;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num >> start >> end;
		pq.push({start,end});
	}

	while(!pq.empty()) {
		if (!lt.empty()) {
			if (lt.top() > pq.top().first) count++;
			else lt.pop();
		}
		else count++;

		lt.push(pq.top().second);
		pq.pop();
	}

	cout << count << "\n";

	return 0;
}