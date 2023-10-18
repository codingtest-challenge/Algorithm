#include <iostream>

using namespace std;

int main()
{
	int n, inum, count=0;
	int arr[10001] = {0, };
	string input;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == "push") {
			cin >> inum;
			arr[count++] = inum;
		}
		if (input == "pop") {
			if (count == 0) cout << -1 << endl;
			else {
				cout << arr[--count] << endl;
				arr[count] == 0;
			}
		}
		if (input == "size") {
			cout << count << endl;
		}
		if (input == "empty") {
			if (count == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (input == "top") {
			if (count == 0) cout << -1 << endl;
			else cout << arr[count - 1] << endl;
		}
	}

	return 0;
}