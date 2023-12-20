#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string S, E, Q;
	string time, name;
	map<string, bool> m;
	map<string, bool> result;


	cin >> S >> E >> Q;

	while (cin >> time >> name) {
		if (time <= S) {
			if (m.find(name) == m.end()) {
				m.insert({ name,true });
			}
		}
		if (time >= E && time <= Q) {
			if (m.find(name) != m.end()) {
				if (result.find(name) != result.end()) continue;
				else {
					result.insert({ name,true });
				}
			}
		}
	}

	cout << result.size() << "\n";

	return 0;
}