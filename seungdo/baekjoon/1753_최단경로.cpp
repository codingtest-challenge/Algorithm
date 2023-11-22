//boj 1753 최단경로 
#include <stdio.h>
#include <iostream>
#include <queue> 
using namespace std;
#define INF 9999999 		// 경로없음 
#define MAX_VERTEX 20001 	// 최대 vertex 개수
#define MAX_EDGE 300001 	// 최대 edge 개수

int d[MAX_VERTEX];
vector<pair<int, int> > edge[MAX_EDGE];

void dijkstra(int start)
{
	
    d[start] = 0;
    //본인에서 본인 가중치 0 
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty())
	{
        int current = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        
        if (d[current] < dist) //이미 최소거리가 있어서 갱신이 안될것같을때  
		{
            continue;
        }
        
        for (int i=0; i<edge[current].size(); ++i)
		{
            int next = edge[current][i].second;
            int nextdist = dist + edge[current][i].first;
            if (d[next] > nextdist)
			{
                d[next] = nextdist;
                pq.push(make_pair(-nextdist, next));
            }
        }
    }
}

int main()
{
    int v, e , start ;
    cin >> v >> e >> start;
    for (int i=1; i<v+1; ++i)
    	d[i] = INF; //최댓값으로 초기화 
    
    for (int i=0; i<e; ++i)
	{
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[a].push_back(make_pair(cost, b));
    }
    dijkstra(start);
    for (int i=1; i<v+1; ++i)
	{
        if (d[i] == INF)
		{
            cout <<"INF"<<"\n";    
        }
        else{
            cout << d[i] << "\n";
        }
    }

    return 0;

}
