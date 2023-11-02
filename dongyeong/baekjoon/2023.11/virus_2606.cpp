#include <iostream>
#include <vector>

using namespace std;

vector <vector<int>> v(101);
bool visit[101] = { false, };
int cnt;

void dfs(int start)
{
	while (!v[start].empty()) {
		int index = v[start].back();
		if (visit[index] == false) {
			visit[index] = true;
			cnt++;
			v[start].pop_back();
			dfs(index);
		}
		else v[start].pop_back();
	}
}

int main()
{
	
	int n, m, a, b;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	visit[1] = true;
	dfs(1);

	cout << cnt << "\n";

	return 0;
}