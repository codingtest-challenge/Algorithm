//boj_21318_피아노체조 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int arr[100001] = {0};
	int arr2[100001] = {0};
	int N;
	cin >> N; 
	for (int i=1;i<=N;i++)
	{
		cin >> arr[i];	
	} 
	for (int i=1;i<N;i++)
	{
		if (arr[i] > arr[i + 1])
		{
			arr2[i] = 1;
		}	
	}
	
	for (int i=2;i<=N;i++)
	{
		arr2[i]=arr2[i]+arr2[i-1];
	}
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << arr2[y]-arr2[x]<<'\n';
	}
	return 0;
}
