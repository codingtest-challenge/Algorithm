#include <iostream>
#include <vector>

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q, x, y, count = 0;
	int cur, nxt;

	cin >> N;

	cin >> cur;

	for (int i = 1; i < N; i++) {
		cin >> nxt;

		if (cur > nxt) arr[i] = ++count;
		else arr[i] = count;
		cur = nxt;
	}

	cin >> Q;

	while (Q--) {
		cin >> x >> y;

		cout << arr[y-1] - arr[x-1] << "\n";
	}

	return 0;
}