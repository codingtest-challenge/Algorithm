#include <iostream>
#include <vector>

using namespace std;

bool visit[100001] = { 0, };
int pNode[100001] = { 0, }; // 부모 노드번호
vector<int> tree[100001]; // 트리연결

void dfs(int a)
{
	visit[a] = true;

	for (int i = 0; i < tree[a].size(); i++) {
		int cNodeA = tree[a][i]; // 해당 노드에 연결된 노드들 하나씩 받아옴
		if (!visit[cNodeA]) { // 해당 노드가 이미 방문한 노드가 아닌 경우(자식노드인 경우)
			pNode[cNodeA] = a;
			dfs(cNodeA);
		}
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // 노드 수
	int x, y; // 인접한 두 노드

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++) {
		cout << pNode[i] << "\n";
	}

	return 0;
}