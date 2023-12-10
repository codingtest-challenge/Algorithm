#include <iostream>
#include <algorithm>
#include <deque>
#define MAX 5000002

using namespace std;

bool arr[MAX];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	bool TF = true;
	deque<char> A;
	int N;
	int b = 0, s = 0;

	cin >> N;

	arr[0] = true;
	arr[1] = true;

	for (int i = 2; i * i <= N; i++) {
		if (arr[i]) continue;
		else {
			for (int j = i; i * j <= N; j++) arr[i*j] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (arr[i]) {
			if (TF) A.push_back('B');
			else A.push_front('B');
			b++;
		}
		else {
			if (TF) {
				if (A.back() == 'B') {
					A.pop_back();
					A.push_back('S');
					A.push_back('S');
					b--;
					s += 2;
				}
				else {
					A.push_back('S');
					TF = !TF;
					s++;
				}
			}
			else {
				if (A.front() == 'B') {
					A.pop_front();
					A.push_front('S');
					A.push_front('S');
					b--;
					s += 2;
				}
				else {
					A.push_front('S');
					TF = !TF;
					s++;
				}
			}
		}
	}

	cout << b << " " << s << "\n";

	return 0;
}