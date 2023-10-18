#include <iostream>
#include<stack>
#include<string>
using namespace std;

void RW(stack <char> &str) {
	while (!str.empty()) {
		cout << str.top();
		str.pop();
	}
}

int main() {
	string S;
	getline(cin, S);

	bool tags = false;

	stack <char> str;

	for (char a : S) {
		if (a == '<')
		{
			RW(str);
			tags = true;
			cout << a;
		}
		else if (a == '>')
		{
			tags = false;
			cout << a;
		}
		else if (tags)
		{
			cout << a;
		}
		else
		{
			if (a == ' ')
			{
				RW(str);
				cout << a;
			}
			else
			{
				str.push(a);
			}
		}
	}
	RW(str);
	cout << '\n';

	return 0;
}