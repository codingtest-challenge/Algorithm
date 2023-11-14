#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N;	// 회의 수 N
	int start, end;	//회의 시작 start, 끝나는 시간 end
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> v;	// 배정된 회의 벡터 v

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;

		pq.push({ end,start });	// 우선순위 큐 pq에 pair로 시작시간, 끝나는 시간 push
	}
	
	v.push_back(pq.top().first);
	pq.pop();

	while (!pq.empty()) {
		if (v.back() <= pq.top().second) {
			v.push_back(pq.top().first);	// 회의실이 사용 가능 할 때 회의 잡히면 배정.
		}

		pq.pop();
	}

	cout << v.size() << "\n";

	return 0;
}