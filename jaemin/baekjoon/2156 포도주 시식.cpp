// 2156 포도주 시식
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> v;
    vector<int> dp;
    int m = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        v.push_back(x);
    }

    

    dp.push_back(v[0]);
    m = v[0];



    for(int i=1; i<n; i++){
        if(i==1){
            dp.push_back(v[i-1] + v[i]);
        }
        else if(i==2){
            dp.push_back(max(dp[i-1], max(v[i]+v[i-1], v[i] + dp[i-2])));
        }

        else{
            dp.push_back(max(v[i]+v[i-1]+dp[i-3], v[i]+dp[i-2]));
            dp[i] = max(dp[i-1], dp[i]);
        }

        m = max(m, dp[i]);
    }


    cout<<m<<endl;

    return 0;
}