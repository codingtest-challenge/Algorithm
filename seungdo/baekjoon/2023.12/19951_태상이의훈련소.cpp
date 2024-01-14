//19951 태상이 의 훈련소 생활 
#include <iostream>
#include <vector>

using namespace std;

int Start[100001];
int End[100001];
int height[100001];
int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		cin >> height[i];
	}
	for(int i=1;i<=M;i++)
	{
		int left,right,value;
		cin >> left >> right >> value;
		Start[left] += value;
		End[right] += value;
	}
	
	int total = 0;
	for(int i=1;i<=N;i++)
	{
		total += Start[i];
		height[i] += total;
		total -= End[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<height[i]<<" ";
	}
	cout<<endl;	
	return 0;

}
