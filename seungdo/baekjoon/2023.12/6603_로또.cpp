//6603_·Î¶Ç 
#include <iostream>
#include <algorithm>

using namespace std;

int k;
int num[14];
int ans[14];

int dfs(int start, int depth)
{
	if(depth==6)
	{
		for(int i=0;i<6;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return 0;
	}
	
	for(int i=start;i<k;i++)
	{
		ans[depth] = num[i];
		dfs(i+1,depth+1);
	}
	return 0; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int temp;
	while(true)
	{
		cin >> k;
		if(k==0) return 0;
		for(int i=0;i<k;i++)
		{
			cin >> temp;
			num[i] = temp;
		}
		dfs(0,0);
		cout<<"\n";
	}
	return 0;
}
