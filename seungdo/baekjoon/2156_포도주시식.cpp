#include <stdio.h>
#include <iostream>
#include <vector>
//#include <algorithm>
//2156 포도주시식 
using namespace std;

int max(int a,int b)
{
	if(a<b) return b;
	return a;
}
int max(int a,int b,int c)
{
	int temp = max(a,b);
	return max(temp,c);
}

int main(void)
{
	int n;
	int dp[10001]={0};
	cin >> n;
	vector<int> v;
	
	for(int i=0;i<n;i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	dp[0] = v[0]; //6
	dp[1] = v[0] + v[1]; //16
	dp[2] = max(v[0]+v[1] , v[0]+v[2], v[1]+v[2]); //23
	dp[3] = max(dp[0]+v[2]+v[3] , dp[1]+v[3], dp[2]); //28
	
	for(int i=3;i<n;i++)
	{
		dp[i] = max(dp[i-3]+v[i-1]+v[i] , dp[i-2] + v[i] , dp[i-1]);
	}
	
	/*
	for(int i=0;i<n;i++) //출력확인 
	{
		cout<< dp[i] << endl;
	}
	*/
	
	cout << dp[n-1] << endl;
	return 0;
}
