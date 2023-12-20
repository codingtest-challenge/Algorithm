//22864 피로도 
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int a,b,c,m;
	//  5 3 2 10
	cin>>a>>b>>c>>m;
	int exp=0; //작업량
	int hp=0; //피로도 
	for(int i=0;i<24;i++)
	{
		if(hp+a <= m) //작업가능  (일) 
		{
			exp += b; //작업량증가 
			hp += a;  //피로도증가 
		}
		else if(hp+a > m) //작업불가 (휴식) 
		{
			hp-=c;	//피로도감소	
			if(hp<0) hp = 0;
		}
	}
	cout << exp;
}
