#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string input;
map<string, int> m;
vector<string> v;

bool compare(string a, string b) {
	if (a.size() == b.size() && m[a] == m[b]) {
		return a < b;
	}
	else if (m[a] == m[b]) {
		return a.size() > b.size();
	}
	return m[a] > m[b];
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;

		if (input.size() < M) continue;

		if (m.find(input) != m.end()) {
			m[input]++;
		}
		else {
			m.insert({ input, 1 });
			v.push_back(input);
		}
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}

	return 0;
}