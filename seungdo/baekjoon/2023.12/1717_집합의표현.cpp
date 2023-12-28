//1717_집합의표현 
#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000001] = {0};
int find(int a);
int check(int a,int b) //같은집합인지? 
{
	if(find(a)==find(b))
	{
		cout<<"YES\n";
		return 0;	
	}
	cout<<"NO\n";
	return 0;
	
}
int unionF(int a,int b)//합치는연산 
{
	int x = find(a);
	int y = find(b);
	if(x==y) return 0;
	if(x<y) arr[y] = x; //작은곳이 루트로 가게끔해주기 
	else arr[x] = y;
	return 0;
}
int find(int a)//루트를 찾는연산 
{
	if(arr[a] == a) //본인이 루트 
		return a;
	return arr[a] = find(arr[a]);
	//아니면 루트를찾을때까지 find 재귀 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++) //집합 초기화 
	{
		arr[i] = i;
	}
	
	int temp,a,b;
	for(int i=0;i<m;i++)
	{
		cin>>temp>>a>>b;
		if(temp==0)
		{
			unionF(a,b);
		}
		else if(temp==1)
		{
			check(a,b);
		}
	}
	return 0;
}
