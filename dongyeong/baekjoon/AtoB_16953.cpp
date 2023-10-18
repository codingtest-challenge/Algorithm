#include <iostream>

using namespace std;

int main()
{
	int A, B;
	int count = 1;

	cin >> A >> B;

	while (B != A) {
		if (B < A) {
			count = -1;
			break;
		}
		if (B % 10 == 1) B /= 10;
		else if (B % 2 == 0) B /= 2;
		else {
			count = -1;
			break;
		}
		count++;
	}

	cout << count << "\n";

	return 0;
}