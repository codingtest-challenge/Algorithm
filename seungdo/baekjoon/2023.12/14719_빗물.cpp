//14719_빗물 
#include <iostream>
#include <algorithm>

using namespace std;
int min(int a,int b)
{
	if(a<b) return a;
	return b;
}
int main()
{
	int H,W;
	cin>>H>>W;
	int height;
	int map[501][3];
	int left_max = 0;
	int right_max = 0;
	int sol = 0;
	for(int i=0;i<W;i++)
	{
		cin >> height;
		map[i][0] = height;
		if(height >= left_max)
		{
			map[i][1] = left_max;
			left_max = height;
		}
		else
		{
			map[i][1] = left_max;
		}
	}
	for(int i=W-1;i>=0;i--)
	{
		height = map[i][0];
		if(height >= right_max)
		{
			map[i][2] = right_max;
			right_max = height;
		}
		else
		{
			map[i][2] = right_max;
		}
	}
	/* 
	for(int i=0;i<W;i++)
	{
		cout << map[i][0] <<" " <<map[i][1] << " "<<map[i][2]<<"\n";
	} 	//예제출력 
	*/
	
	
	for(int i=1;i<W-1;i++) 	//왼쪽끝 오른쪽끝 제외 
	{						//본인의 위치에서 얼마나 고이는지 
		int minimum = min(map[i][1],map[i][2]);
		if(minimum > map[i][0])
		{
			sol += minimum - map[i][0];
		}
	}
	cout << sol << endl;
	
}
