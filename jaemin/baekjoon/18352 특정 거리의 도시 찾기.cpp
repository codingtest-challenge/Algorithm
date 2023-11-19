#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v[300001];
vector<int> res;
int visited[300001];

void bfs(int x, int k){
    queue<int> q;
    visited[x] = -1;

    q.push(x);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<v[cur].size(); i++){
            int nxt = v[cur][i];
            if(visited[nxt]==0){
                if(visited[cur] == -1)
                    visited[nxt] = visited[cur] + 2;
                else 
                    visited[nxt] = visited[cur] + 1;
                if(visited[nxt] == k){
                    res.push_back(nxt);
                }
                q.push(nxt);
            }
        }
    }
}

int main(){
    int n, m, k, x;

    cin>>n>>m>>k>>x;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    bfs(x, k);

    if(res.empty()){
        cout<<-1<<"\n";
    }
    
    else{
        sort(res.begin(), res.end());
        for(int i=0; i<res.size(); i++){
            cout<<res[i]<<"\n";
        }
    }


    return 0;
}