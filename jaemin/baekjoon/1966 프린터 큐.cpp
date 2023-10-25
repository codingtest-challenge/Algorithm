// 1966 프린터 큐

#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int n = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		queue<int> q;
		int a, b;
		int cnt = 0;

		cin >> a >> b;

		int pri[100] = { 0, };

		for (int j = 0; j < a; j++) {
			cin >> pri[j];
		}

		for (int j = 0; j < a; j++) {
			cin >> pri[j];
		}
	}




	return 0;
}