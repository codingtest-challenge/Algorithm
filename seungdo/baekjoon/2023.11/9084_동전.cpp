//boj 9084 동전 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T,N,M;
	int coin[21] = {0};
	cin >> T;
	
	for(int i=0;i<T;i++)
	{
		for(int i=1;i<=20;i++) coin[i] = 0; //초기화 
		cin >> N;
		for(int j=1;j<=N;j++)
		{
			int temp;
			cin >> temp;
			coin[j] = temp;
		}
		cin >> M; //만들금액 
		
		int d[10001] = {0};
		d[0] = 1;
		
		for(int i=1;i<=N;i++)
		{
			for(int j = coin[i];j<=M;j++)
			{
				d[j] = d[j] + d[j - coin[i]];
			}
		}
		cout << d[M] << endl;
		
	}
	return 0; 
}

