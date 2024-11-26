#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, d;

    vector<pair<int, int>> v[10001];
    vector<int> res;
    
    cin>>n>>d;
    
    for(int i=0; i<n; i++){
        int x, y, len;
        cin>>x>>y>>len;
        v[y].push_back({x, len});
    }
    res.push_back(0);
    for(int i=1; i<=d; i++){
        res.push_back(res[i-1] + 1);
        for(int j=0; j<v[i].size(); j++){
            int x = v[i][j].first;
            int len = v[i][j].second;
            res[i] = min(res[i], res[x] + len);
        }
    }
    
    cout<<res[d]<<"\n";
    
    return 0;
}
