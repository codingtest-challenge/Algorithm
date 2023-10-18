#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	string S, output;
	bool TF;
	map<string, int>m;
	map<string, int>::iterator it;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> S;
		TF = false;
		output = "";
		for (int j = 0; j < S.size(); j++) {
			if (TF == true) output += S[j];
			else if (S[j] == '.') TF = true;
		}
		if (m.find(output) != m.end()) {
			m.find(output)->second++;
		}
		else m.insert({ output,1 });
	}

	for (it = m.begin(); it != m.end(); it++) {
		cout << it->first << ' ' << it->second << "\n";
	}

	return 0;
}