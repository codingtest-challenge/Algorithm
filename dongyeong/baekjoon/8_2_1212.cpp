#include <iostream>
#include <queue>

using namespace std;

int main()
{
	string n;
	int a;
	queue<int> result;

	cin >> n;
	
	if (n == "0") cout << "0\n";
	else {
		for (int i = 0; i < n.size(); i++) {
			a = n[i] - '0';
			result.push(a / 4);
			result.push((a % 4) / 2);
			result.push(a % 2);
		}
		while (true) {
			if (result.front() == 0) result.pop();
			else break;
		}
		while (!result.empty()) {
			cout << result.front();
			result.pop();
		}
	}

	return 0;
}