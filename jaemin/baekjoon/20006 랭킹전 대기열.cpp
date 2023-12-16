// 20006 랭킹전 대기열

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
}

int main(){
    int p, m;
    vector<pair<int, string>> room[300];

    cin>>p>>m;

    for(int i=0; i<p; i++){
        int x; string y;
        cin>>x>>y;
        for(int j=0; j<300; j++){
            if(room[j].size() == m){
                continue;
            }

            if(!room[j].empty()){
                int f = room[j][0].first;
                if(abs(f-x) <= 10){
                    room[j].push_back({x, y});
                    break;
                }
            }
            else{
                room[j].push_back({x, y});
                break;
            }
        }
    }

    int i=0;

    while(1){
        if(room[i].empty()) break;

        if(room[i].size() == m){
            cout<<"Started!"<<endl;
        }

        else{
            cout<<"Waiting!"<<endl;
        }
        sort(room[i].begin(), room[i].end(), cmp);
        for(int j=0; j<room[i].size(); j++){
            cout<<room[i][j].first<<" "<<room[i][j].second<<endl;
        }

        i++;
    }

    return 0;
}

