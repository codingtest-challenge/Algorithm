// 2553번 마지막 팩토리얼 수

#include <iostream>
using namespace std;

int main() {
	int n;
	int b = 0;

	cin >> n;


	for (int i = n; i >= 2; i--) {
		int a = i - 1;

		while (1) {
			if (n % 10 == 0) {
				n /= 10;
			}
			else {
				n = a * (n % 10);
				break;
			}
		}
	}

	cout << n << endl;

	return 0;
}