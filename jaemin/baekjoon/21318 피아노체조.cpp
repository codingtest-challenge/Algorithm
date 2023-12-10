#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    vector<int> v;
    vector<int> res;

    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);

        if(i==0) res.push_back(0);
        else{
            if(v[i] < v[i-1]) res.push_back(res[i-1]+1);
            else res.push_back(res[i-1]);
        } 
    }

    int t;

    cin>>t;

    for(int i=0; i<t; i++){
        int x, y;
        cin>>x>>y;
        cout<<res[y-1] - res[x-1]<<"\n";
    }


    return 0;
}