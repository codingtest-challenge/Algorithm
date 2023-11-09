#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> H;	// 각 풍선의 높이 입력값
	vector<int> v;	// 화살 높이. v.size()==화살 갯수

	cin >> N;

	for (int i = 0; i < N; i++) {
		int input;

		cin >> input;
		H.push_back(input);
	}

	v.push_back(H.back());
	H.pop_back();

	while (!H.empty()) {
		bool check = true;	// 이미 던진 화살중 하나가 해당 높이에 있으면 false, 없으면 true
		int size = v.size();

		for (int i = 0; i < size; i++) {
			if (v[i] + 1 == H.back()) {
				v[i]++;
				check = false;
				break;
			}
		}

		if (check) v.push_back(H.back());

		H.pop_back();
	}

	cout << v.size() << "\n";

	return 0;
}