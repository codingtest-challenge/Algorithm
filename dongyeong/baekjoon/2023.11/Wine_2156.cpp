#include <iostream>
#include <algorithm>

using namespace std;

int arr[10002] = { 0, }; // 포도주의 양 배열
int mMount[10002] = { 0, };	// 포도주 최대 양

int main()
{
	int n;	// 포도주 잔 수량

	cin >> n; // 잔 수량 입력

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];	//각 포도주의 양 입력
	}

	mMount[1] = arr[1];
	mMount[2] = arr[1] + arr[2];

	if (n == 1) cout << mMount[1] << "\n";	// 수량 1인 경우
	else if (n == 2) cout << mMount[2] << "\n";	// 수량 2인 경우
	else {
		for (int i = 3; i <= n; i++) {	// 수량이 3 이상인 경우
			mMount[i] = max(mMount[i - 3] + arr[i - 1] + arr[i], max(mMount[i - 2] + arr[i], mMount[i-1]));
		}

		cout << mMount[n] << "\n";
	}

	return 0;
}