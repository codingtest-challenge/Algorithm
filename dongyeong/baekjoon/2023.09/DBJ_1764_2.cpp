#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, count = 0;
	string input;
	
	map < string, bool > n;
	map < string, bool > m;
	map<string, bool>::iterator it;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> input;

		n.insert({ input,true });
	}

	for (int i = 0; i < M; i++) {
		cin >> input;

		m.insert({input,true});
		if (n.find(input) != n.end()) count++;
	}

	cout << count << "\n";

	for (it = n.begin(); it != n.end(); it++) {
		if (m.find(it->first)!=m.end()) {
			cout << it->first << "\n";
		}
	}

	return 0;
}