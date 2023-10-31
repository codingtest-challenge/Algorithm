// 15486 퇴사2

#include <iostream>
using namespace std;

int main(){

    int n;
    int t[100000] = {0,};
    int p[100000] = {0,};
    int dp[100000] = {0,};

    int m = 0;
    


    cin>>n;

    for(int i=0; i<n; i++){
        cin>>t[i]>>p[i];
    }

    for(int i=0; i<=n; i++){
        dp[i] = max(m, dp[i]);
       
       if(i + t[i] <= n){
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
       }

       m = max(m, dp[i]);
    }



   cout<<m<<endl;


    return 0;
}