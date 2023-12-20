#include <iostream>
#include <vector>
#include <math.h>
int prime[5000001];
using namespace std;

int main(void)
{
	int A;
	int N;
	cin >> N;
	for(int i=0;i<=N;i++)
	{
		prime[i] = {1,};
	}
	for(int i=2;i*i<=N;i++)
	{
		if(prime[i] == 0) continue;
		for(int j = 2; j*i<=N; j++)
			prime[i*j] = 0;
	}
	
	//if(prime[N] == 0) cout<<"not prime"<<endl;
	
	int B = 0;
	int S = 0;
	for(int i=1;i<=N;i++)
	{
		if(i==1)
		{
			B++;
			continue;
		}
		if(i==2)
		{
			B--;
			S+=2;	
			continue;
		}
		if(i==3) 
		{
			S++;
			continue;
		}
		if(prime[i]==0)//소수아닐때
		{
			B++;
		}
		else //소수일때 
		{
			B--;
			S+=2;
		}
		
	}
	cout << B << " " << S << endl;
	// 1 -> B      1  0
	// 2 -> SS     0  2
	// 3 -> SSS    0  3
	// 4 -> SSSB   1  3
	// 5 -> SSSSS  0  5
	// 6 -> SSSSSB 1  5
	// 7 -> SSSSSSS 0 7
	// 8 -> SSSSSSSB 1 7
	// 9 -> 2 7
	return 0;
}
