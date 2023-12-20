//19583 싸이버개강총회
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int cal(string s)
{
	int temp;
	temp = 60 * stoi(s.substr(0,2)) + stoi(s.substr(3,2));
	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string start,mid,end;
	cin>>start>>mid>>end;
	
	int s = cal(start);
	int m = cal(mid);
	int e = cal(end);
	
	string time,name;
	int t,count=0;
	set<string> first;
	while(cin>>time>>name)
	{
		t = cal(time);
		if(t<=s)
		{	//조건 1.총회시작전에 출석 
			first.insert(name); 
		}
		if(m <= t && t <= e)
		{	// 조건 2. 총회가 끝나고 스트리밍이 끝나기 전에 출석 
			if(first.find(name) != first.end())
			{	//둘다 만족하면 출석완료 
				count++;
				first.erase(name);
			}
		}
	}
	
	cout<<count<<endl;
	return 0;
}
