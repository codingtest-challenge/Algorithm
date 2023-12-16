// 19951 태상이의 훈련소 생활

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    vector<int> v;
    vector<int> p;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        v.push_back(x);
        p.push_back(0);
    }
    p.push_back(0);

    for(int i=0; i<m; i++){
        int a, b, k;
        cin>>a>>b>>k;

        p[a-1] += k;
        p[b] -= k;
    }

    for(int i=1; i<n; i++){
        p[i] += p[i-1];
    }

    for(int i=0; i<n; i++){
        cout<<v[i] + p[i]<<" ";
    }
    cout<<"\n";


    return 0;
}