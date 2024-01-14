#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	long long int X, Y;
	long long int tall, stall, ans=0;

	cin >> X >> Y;

	tall = Y - X;
	stall = sqrt(tall);

	if (tall == 0) cout << "0\n";
	else if (stall * stall == tall) cout << stall * 2 - 1 << "\n";
	else {
		if (tall <= stall * stall + stall) cout << stall * 2 << "\n";
		else cout << stall * 2 + 1 << "\n";
	}

	return 0;
}