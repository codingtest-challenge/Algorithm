#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int p, m, l, count=0;
    string n;
    vector<pair<string,int>> v[302];

    cin >> p >> m;

    for (int i = 0; i < p; i++) {
        cin >> l >> n;

        bool TF = false;

        for (int j = 0; j <= i; j++) {
            if (v[j].size() > 0 && v[j].size() < m && abs(v[j][0].second - l) <= 10) {
                TF = true;
                v[j].push_back({n,l});
                break;
            }
        }

        if (!TF) {
            v[count++].push_back({n,l});
        }
    }

    for (int i = 0; i < count; i++) {
        if (v[i].size() == m) {
            cout << "Started!" << endl;
        }
        else {
            cout << "Waiting!" << endl;
        }

        sort(v[i].begin(), v[i].end());

        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j].second << " " << v[i][j].first << "\n";
        }
    }

    return 0;
}