#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int result;
int N;

long long int cal(int a) {
	long long int sum = 0;

	for (int i = 0; i < N; i++) {
		if (v[i] < a) sum += v[i];
		else sum += a;
	}

	return sum;
}

void bs(int start, int end, long long int M) {
	int mid = (start + end) / 2;
	long long int sum = cal(mid);

	if (start > end) return;

	if (sum <= M) {
		result = mid;
		bs(mid+1, end, M);
	}

	else {
		bs(start, mid - 1, M);
	}
}

int main()
{
	int input, mx=0;
	long long int sum=0, M;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;

		v.push_back(input);
		sum += input;
		mx = max(mx, input);
	}

	cin >> M;

	if (sum <= M) cout << mx << "\n";
	else {
		bs(0, mx, M);

		cout << result << "\n";
	}

	return 0;
}