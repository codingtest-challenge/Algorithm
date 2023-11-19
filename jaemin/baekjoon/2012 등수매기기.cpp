#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n = 0;
    long long res = 0;
    vector<int> v;
    
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        res += abs((i+1) - v[i]);
    }

    cout<<res<<"\n";

    return 0;
}