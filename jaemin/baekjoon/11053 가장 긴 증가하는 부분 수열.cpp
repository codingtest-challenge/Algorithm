#include <iostream>
using namespace std;

int main() {
	int n;

	int arr[1000] = {0,};
	int dp[1000] = {0,};
	int res = 1;

	cin>>n; 

	for(int i=0; i<n; i++){
		cin>>arr[i];
		dp[i] = 1;
	}

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i], dp[j] + 1);
				res = max(dp[i], res);
			}
		}

	}

	cout<<res<<endl;




	return 0;
}