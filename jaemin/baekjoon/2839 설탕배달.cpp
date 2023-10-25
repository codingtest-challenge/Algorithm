// 2839 º≥≈¡πË¥ﬁ

#include <iostream>
using namespace std;

int main() {


	int n;
	int m = 99999;

	cin >> n;


	if (n % 3 == 0) {
		m = n / 3;
	}

	int cnt = n / 5;
	
	while (1) {
		if (cnt == 0) break;

		if ((n - cnt * 5) % 3 == 0) {
			m = cnt + (n - cnt * 5) / 3;
			break;
		}

		cnt--;
	}

	cout << (m != 99999 ? m : -1) << "\n";
	


	return 0;
}