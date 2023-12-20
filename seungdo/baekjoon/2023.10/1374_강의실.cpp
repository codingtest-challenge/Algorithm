//1374 강의실 
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main()
{
	int N , count=0;
	cin >> N;
	
	vector<vector<int> > v(N);
	
	for(int i=0;i<N;i++)  //입력 
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[i].push_back(b);
		v[i].push_back(c);
	}
	
	sort(v.begin(), v.end());
	
	//예제출력
	/*
	cout<<"정렬 "<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		//cout<<endl;
	}
	*/
	//출력끝 
	
	priority_queue<int> pq;
	
	for(int i=0;i<N;i++)
	{
		//cout<<"i == "<<i<<" 일때"<<endl;
		
		while(!pq.empty() && -pq.top()<=v[i][0])
		{
			cout << "pq.top " <<-pq.top()<<endl;
			pq.pop();
		}
		
		pq.push(-v[i][1]);
		
		if(count < pq.size())
		{
			count = pq.size();
		}
		//cout<<"size == " <<pq.size() << endl;
	}
	
	
	
	cout << count;
}
