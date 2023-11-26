#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;

    cin>>t;

    for(int s=1; s<=t; s++){
        int n, m;
        vector<int> coin;
        int dp[10001] = {0,};

        dp[0] = 1;

        cin>>n;

        for(int i=0; i<n; i++){
            int input;
            cin>>input;
            coin.push_back(input);
        }

        cin>>m;



        for(int i=0; i<coin.size(); i++){
            int x = coin[i];
            for(int j=x; j<=m; j++){
                dp[j] += dp[j - x];
            }

        }

        cout<<dp[m]<<endl;

    }

    return 0;
}