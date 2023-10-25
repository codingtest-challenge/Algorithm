#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int arr[1024];
int K, Nodes;
vector<int> tree[10];

void makeTree(int start, int end, int depth) {
	if (depth >= K)
		return;

	if (start == end) {
		tree[depth].push_back(arr[start]);
		return;
	}

	int mid = (start + end) / 2;

	if (mid < 0 || mid >= Nodes)
		return;

	tree[depth].push_back(arr[mid]);

	makeTree(start, mid - 1, depth + 1);
	makeTree(mid + 1, end, depth + 1);

}

int main()
{
	cin >> K;

	Nodes = pow(2, K) - 1;

	for (int i = 0; i < Nodes; i++) {
		cin >> arr[i];
	}

	makeTree(0, Nodes - 1, 0);

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < tree[i].size(); j++) {
			cout << tree[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}