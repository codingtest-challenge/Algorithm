#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int arr[1500002] = { 0, };

void dp(int N, int M)
{

	if (N == -1) return;

	if (N + v[N].first > M) {
		arr[N] = arr[N+1];
	}
	else {
		arr[N] = max(arr[N + 1], v[N].second + arr[N + v[N].first]);
	}

	dp(N - 1, M);
}

int main()
{
	int N, T, P;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> T >> P;
		v.push_back(make_pair(T, P));
	}

	dp(N-1,N);

	cout << arr[0] << "\n";

	return 0;
}