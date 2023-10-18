#include  <iostream>

using namespace std;

int main()
{
	int n;
	int count = 0;

	cin >> n;

	if ((n % 5) % 2 != 0) {
		if (n == 1 || n==3) count = -1;
		else {
			count += n / 5 - 1;
			count += (n % 5 + 5) / 2;
		}
	}
	else {
		count += n / 5;
		count += (n % 5) / 2;
	}
	
	cout << count << "\n";

	return 0;
}