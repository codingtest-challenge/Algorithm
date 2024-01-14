#include <iostream>
#include <vector>

using namespace std;

vector<long long int> v;
int maxi = -1000000000;
int mini = 1000000000;

void calc(int a, int ans, int pl, int mi, int mul, int di) {
	if (pl == 0 && mi == 0 && mul == 0 && di == 0) {
		if (ans > maxi) maxi = ans;
		if (ans < mini) mini = ans;
		return;
	}
	if (pl != 0) {
		int temp = ans + v[a];
		calc(a + 1, temp, pl-1, mi, mul, di);
	}
	if (mi != 0) {
		int temp = ans - v[a];
		calc(a + 1, temp, pl, mi-1, mul, di);
	}
	if (mul != 0) {
		int temp = ans * v[a];
		calc(a + 1, temp, pl, mi, mul-1, di);
	}
	if (di != 0) {
		int temp = ans / v[a];
		calc(a + 1, temp, pl, mi, mul, di-1);
	}

}

int main()
{
	int N;
	int pl, mi, mul, di;	

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;

		v.push_back(input);
	}

	cin >> pl >> mi >> mul >> di;

	calc(1, v[0], pl, mi, mul, di);

	cout << maxi << "\n" << mini << "\n";

	return 0;
}