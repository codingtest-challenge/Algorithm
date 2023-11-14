// 1753 최단경로

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;
vector<pair<int, int>> gr[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int W[20001];

void dijkstra(int k){
    q.push({0, k});

    while(!q.empty()){
        int dis = q.top().first;
        int pos = q.top().second;
        q.pop();
        for(int i=0; i<gr[pos].size(); i++){
            int nxt = gr[pos][i].first;
            int wnxt = gr[pos][i].second;
            if(W[pos]+wnxt < W[nxt]){
                W[nxt] = W[pos] + wnxt;
                q.push({W[nxt], nxt});
            }
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int V, E;
    int K;

    fill_n(W, 20001, INF);
    cin>>V>>E>>K;

    W[K] = 0;
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        gr[u].push_back({v, w});
    }

    dijkstra(K);

    for(int i=1; i<=V; i++){
        if(W[i] == INF) cout<<"INF"<<"\n";
        else cout<<W[i]<<"\n";
    }


    return 0;
}