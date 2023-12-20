//boj 18352 특정거리의 도시 찾기 
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX_VERTEX 300001
#define MAX 9999999
#define MAX_EDGE 1000001
using namespace std; 

int d[MAX_VERTEX]={0};
vector<pair<int, int> > edge[MAX_EDGE];
void dijkstra(int start)
{
	d[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push({0,start});
	
	while(!pq.empty())
	{
		int current = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(d[current] < dist) continue;
		
		for(int i=0; i<edge[current].size(); i++)
		{
			int next = edge[current][i].second;
			int nextdist = dist + edge[current][i].first;
			if(d[next] > nextdist)
			{
				d[next] = nextdist;
				pq.push(make_pair(-nextdist,next));
			}
		}
	}

}

int main(void)
{
	int N,M,K,X; //도시의개수,도로의개수,거리정보,도시번호 	
	cin >> N >> M >> K >> X;
	for(int i=0;i<M;i++)
	{
		int A,B;
		cin>>A>>B;
		edge[A].push_back({1,B}); //A에서 B까지는 거리가 1 
	}
	
	for(int i=1;i<=N;i++) //간선간 최소거리 999999로 초기화 
	{
		d[i] = MAX;
	}
	
	dijkstra(X);
	
	int count = 0;
	for(int i=1;i<=N;i++)
	{
		if(d[i] == K)
		{
			cout<<i<<"\n";
			count++;
		}
	}
	if(count == 0)
	{
		cout<<"-1\n";
	}
	/*
	for(int i=0;i<M;i++)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	*/
	return 0;
}
