// 1717 집합의 표현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000001];

int getParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int find(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b) return 1;
    else return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;

    cin>>n>>m;

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }


    for(int i=0; i<m; i++){
        int x, a, b;
        cin>>x>>a>>b;

        if(x==0) unionParent(a, b);

        else{
            if(find(a, b) == 0) cout<<"NO"<<"\n";
            else cout<<"YES"<<"\n";
        }

        for(int j=1; j<=n; j++){
            cout<<parent[j]<<" ";
        }
        cout<<endl;
      
    }



    return 0;
}