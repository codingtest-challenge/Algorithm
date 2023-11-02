#include <iostream>
#include <algorithm>

using namespace std;



int main() {
	int sol[2001] = { 0, }; // 병사 전투력
	int arr[2001] = { 0, };
	int N, cnt = 0;


	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> sol[N - i - 1]; // 오름차순으로 생각하도록 뒤집음
		arr[i] = 1; // N개의 해당 배열 인덱스의 값을 1로 초기화
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (sol[i] > sol[j]) arr[i] = max(arr[i], arr[j] + 1);
		}
	}

	for (int i = 0; i < N; i++) {
		if (cnt < arr[i]) cnt = arr[i];
	}

	cout << N - cnt << "\n";

	return 0;
}