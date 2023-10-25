#include <iostream>
#include <queue>
using namespace std;

int map[50][50] = { 0, };

int rx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int ry[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };

bool check(int x, int y, int w, int h) {
	
	if (x < 0 || x >= h) return false;
	if (y < 0 || y >= w) return false;
	if (map[x][y] != 1) return false;
	return true;
}

void bfs(int x, int y, int w, int h) {

	queue<pair<int, int>> q;
	
	q.push({ x, y });

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {

			int x1 = x + rx[i];
			int y1 = y + ry[i];

			if (check(x1, y1, w, h)) {
				map[x1][y1] = 0;
				q.push({ x1, y1 });
			}
		}
	}
}

int main() {
	
	int w, h;

	while (1) {
		bool visited[50][50] = { 0, };
		int cnt = 0;
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1) {
					bfs(i, j, w, h);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	

	return 0;
}