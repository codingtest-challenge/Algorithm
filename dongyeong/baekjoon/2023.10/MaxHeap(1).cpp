#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	priority_queue<int> Mheap;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (!Mheap.empty()) {
				cout << Mheap.top() << "\n";
				Mheap.pop();
			}
			else cout << 0 << "\n";
		}
		else Mheap.push(x);
	}

	return 0;
}