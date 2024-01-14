//20438_출석체크 
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,K,Q,M;
	int student[5001]={1,};
	bool sleep[5001]={false};
	int left,right;
	int S,E;
	
	cin >> N >> K >> Q >> M; //1번째줄 입력 
	for(int i=0;i<K;i++) //졸고있는 학생 입력 
	{
		int temp;
		cin >> temp;
		sleep[temp] = true;
	}
	for(int i=3;i<=N+2;i++)
	{
		student[i] = 1;
	}
		
	for(int i=0;i<Q;i++) //출석 코드를 받을 학생 입력 
	{
		int temp;
		cin >> temp;
		if( sleep[temp] ) continue;//졸고있으면 코드못받음
		for(int j=temp;j<=N+2;j+=temp)
		{
			if(sleep[j]) continue; //졸면 스킵 
			student[j] = 0;
		}
	}
	for(int i=4;i<=N+2;i++)
	{
		student[i] += student[i-1];
	}
		
	for(int i=0;i<M;i++) //M개의 줄동안 S , E 범위 
	{
		cin>>left>>right;
		cout<<student[right] - student[left - 1] <<'\n';
	}
	
	//구간 입력 
	
	
	return 0;
}
