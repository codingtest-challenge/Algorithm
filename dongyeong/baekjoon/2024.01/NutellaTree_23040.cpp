#include <iostream>
#include <vector>

using namespace std;

char RB[100001];
vector<int> nutella[100001];
int cnt = 0;

void search(int a, int b) {
	if (a == -1) {
		for (int i = 0; i < nutella[b].size(); i++) {
			if (RB[nutella[b][i]] == 'R') {
				cnt++;
				search(b, nutella[b][i]);
			}
		}
	}
	else {
		for (int i = 0; i < nutella[b].size(); i++) {
			if (nutella[b][i] != a && RB[nutella[b][i]] == 'R') {
				cnt++;
				search(b, nutella[b][i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	vector<int> start;

	for (int i = 0; i < N - 1; i++) {
		int a, b;

		cin >> a >> b;
		nutella[a].push_back(b);
		nutella[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		cin >> RB[i];
		if (RB[i] == 'B') start.push_back(i);
	}

	for (int i = 0; i < start.size(); i++) {
		search(-1,start[i]);
	}

	cout << cnt << "\n";

	return 0;
}