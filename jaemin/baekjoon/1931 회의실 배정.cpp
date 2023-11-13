#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b){

    if(a.second == b.second){
        return a.first < b.first;
    }
    else
        return a.second < b.second;
}

int main(){

    int n;
    int cnt = 0;
    priority_queue<int> q;
    vector<pair<int, int>> v;

    cin>>n;

    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), compare);

    int st = v[0].second;

    for(int i=1; i<n; i++){
        if(v[i].first >= st){
            st = v[i].second;
            cnt++;
        }
    }

    cout<<cnt+1<<endl;


    return 0;
}
