#include <iostream>
#include <vector>

using namespace std;

int arr[1000001];

int find(int a) {
	if (arr[a] < 0) return a;

	arr[a] = find(arr[a]);

	return find(arr[a]);
}

void uni(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	arr[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int calc, a, b;

	fill(arr, arr + 1000001, -1);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> calc >> a >> b;

		if (calc == 0) {
			uni(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}