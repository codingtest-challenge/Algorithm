// 2407 а╤гу

#include <iostream>
using namespace std;

long long arr[101][101];

long long  combi(int n, int m) {
	if (n == m || m == 0) return 1;

	if (arr[n][m] != 0) return arr[n][m];

	return arr[n][m] = combi(n - 1, m - 1) + combi(n - 1, m);
}

int main() {
	long long  n, m;

	cin >> n >> m;

	combi(n, m);

	cout<<arr[n][m]<<endl;

	return 0;
}