//18312 ½Ã°¢ 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
bool check(int a,int b,int c,int x)
{
	if(a>=10 && a/10 == x) return true;
	if(b>=10 && b/10 == x) return true;
	if(c>=10 && c/10 == x) return true;
	if(a%10 == x || b%10 == x || c%10 == x) return true;
	
	if(a<10 || b<10 || c<10)
	{
		if(x==0) return true;
	}
	return false;
}
int main(void)
{
	int N,K;
	int count = 0;
	cin >> N >> K;
	for(int h=0;h<=N;h++)
	{
		for(int m=0;m<=59;m++)
		{
			for(int s=0;s<=59;s++)
			{
				if( check(h,m,s,K) == true )
				{
					//cout<<h<<" "<<m<<" "<<s<<endl;
					count++;
				}
			}
		}
	}
	cout<<count;
}
