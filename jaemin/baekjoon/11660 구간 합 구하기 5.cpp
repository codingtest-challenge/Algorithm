// 11660 구간 합 구하기

#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    int arr[102][102] = { 0, };
    int res[102][102] = { 0, };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            res[i][j] = res[i][j - 1] + arr[i][j];

        }
    }

    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = x1; i <= x2; i++) {
            sum += res[i][y2] - res[i][y1 - 1];
        }

        cout << sum << "\n";
    }



    return 0;
}
 