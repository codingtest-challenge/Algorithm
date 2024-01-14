#include <iostream>
#include <vector>
//#include <algorithm>
//11509 풍선맞추기 

using namespace std;

vector<int> v;
int N;
int count = 0;
int dp[1000001] = {0};

int main(void) 
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for(int i=0;i<N;i++)
	{
		int height = v[i];
		if(dp[height] > 0) // 해당높이 화살을 찾음 
		{
			dp[height]--;
			dp[height-1]++;
			
			//cout<<"찾음 height == "<<height<<"  count == "<<count<<endl;
		}
		else  //해당높이에 없음- 화살을쏜다 
		{
			dp[height - 1]++;
			count++;
			
			//cout<<"못찾음 height == "<<height<<" count == "<<count<<endl;
		}
	}
	cout << count << endl;
	return 0;
}
