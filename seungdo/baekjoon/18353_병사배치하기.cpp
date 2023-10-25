#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
//18353 병사배치하기 
using namespace std;

int max(int a, int b) 
{
	if(a<b) return b;
	return a;
}


int main(void)
{
	vector<int >v;
	int dp[2001][2]={0};  	//[0] 최대 오름차순 수열 
							//[1]  전투력 저장 
												
	//입력						
	int N,temp;  			// 병사의 수  
	int count = N;
	int ans = 0;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		v.push_back(temp);
	} //입력 끝 
	
	reverse(v.begin(),v.end());
	for(int i = 0; i< N; i ++)
	{
		dp[i][0] = 1;
	}

	for(int i=1;i<N;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[j] < v[i])
			{
				dp[i][0] = max(dp[i][0],dp[j][0] + 1);
			}
		}
	}
	
	/*for(int i=0;i<N;i++)
	{
		cout<<v[i]<<" ";	
	}
	cout<<endl;
	*/
	for(int i=0;i<N;i++)
	{
		ans = max(ans,dp[i][0]);
		//cout<<dp[i][0]<<endl;
	}
	
	
	
	cout<<N - ans<<"\n";
}
