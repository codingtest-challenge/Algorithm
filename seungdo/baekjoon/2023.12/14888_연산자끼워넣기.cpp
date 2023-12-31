//14888 연산자끼워넣기  
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int arr[12];
int op[4];
int N;
int min_num = INT_MAX;
int max_num = INT_MIN;
int dfs(int x,int index)
{
	if(index == N)
	{
		if(x < min_num) min_num = x;
		if(x > max_num) max_num = x;
		return 0;
	}
	for(int i=0;i<4;i++)
	{
		if(op[i] == 0) continue;
		op[i]--;
		if(i==0) dfs(x+arr[index],index+1);
		if(i==1) dfs(x-arr[index],index+1);
		if(i==2) dfs(x*arr[index],index+1);
		if(i==3) dfs(x/arr[index],index+1);
		op[i]++;
	}
	return 0;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int temp;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin>>temp;
		arr[i] = temp;
	}
	for(int i=0;i<4;i++) cin>>op[i];
	dfs(arr[0],1);
	cout<<max_num<<"\n"<<min_num;
	return 0;
}
