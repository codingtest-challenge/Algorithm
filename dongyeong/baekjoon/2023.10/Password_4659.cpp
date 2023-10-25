#include <iostream>
#include <string>

using namespace std;

const bool FC(string tc) {
	int count = 0;
	for (int i = 0; i < tc.size(); i++) {
		if (tc[i] == 'a' || tc[i] == 'e' || tc[i] == 'i' || tc[i] == 'o' || tc[i] == 'u') count++;
		if (i>0) if (tc[i] == tc[i - 1] && tc[i] != 'e' && tc[i] != 'o') return false;
		if (i > 1) if (tc[i] == 'a' || tc[i] == 'e' || tc[i] == 'i' || tc[i] == 'o' || tc[i] == 'u') {
			if (tc[i - 1] == 'a' || tc[i - 1] == 'e' || tc[i - 1] == 'i' || tc[i - 1] == 'o' || tc[i - 1] == 'u') {
				if (tc[i - 2] == 'a' || tc[i - 2] == 'e' || tc[i - 2] == 'i' || tc[i - 2] == 'o' || tc[i - 2] == 'u') {
					return false;
				}
			}
		}
		if (i > 1) if (tc[i] != 'a' && tc[i] != 'e' && tc[i] != 'i' && tc[i] != 'o' && tc[i] != 'u') {
			if (tc[i - 1] != 'a' && tc[i - 1] != 'e' && tc[i - 1] != 'i' && tc[i - 1] != 'o' && tc[i - 1] != 'u') {
				if (tc[i - 2] != 'a' && tc[i - 2] != 'e' && tc[i - 2] != 'i' && tc[i - 2] != 'o' && tc[i - 2] != 'u') {
					return false;
				}
			}
		}
	}
	if (count == 0) return false;
	else return true;
}

int main()
{
	string tc;

	while (true) {
		cin >> tc;

		if (tc == "end") break;
		else if (FC(tc)) cout << "<" << tc << "> is acceptable." << "\n";
		else cout << "<" << tc << "> is not acceptable." << "\n";

	}

	return 0;
}