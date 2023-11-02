// 11660 구간 합 구하기

#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;

    cin>>n>>m;

    int arr[100][100] = {0,};
    int dp[100][100] = {0,};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];

            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    

    for(int i=1; i<=m; i++){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;

        int sum = dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1];

        cout<<sum<<"\n";
    }

    
}