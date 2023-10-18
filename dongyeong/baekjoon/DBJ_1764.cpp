#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	string input;

	vector<string> m;

	cin >> N >> M;

	string* n = new string[N];

	for (int i = 0; i < N; i++) {
		cin >> input;

		n[i] = input;
	}

	sort(n, n + N);

	for (int i = 0; i < M; i++) {
		cin >> input;

		m.push_back(input);
	}

	for (int i = 0; i < N; i++) {
		if (find(m.begin(), m.end(), n[i]) != m.end()) {
			cout << n[i] << "\n";
		}
	}
	
	delete[] n;

	return 0;
}