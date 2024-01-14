//boj 16928 뱀과사다리게임
#include <iostream> 
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[101] = {0};
bool visited[101] = {0};
void game(int a,int b)
{
	queue <pair<int, int> > q;
	q.push({a,b});
	while(!q.empty())
	{
		int current = q.front().first;
		int count = q.front().second;
		q.pop();
		
		for(int i=1;i<=6;i++)
		{
			int next = current + i;
			if(next == 100)			//종료 
			{
				cout << count + 1;
				return ;
			}
			else if(next < 100)
			{
				while(map[next] != 0) //끝날때까지 위나 아래로점프 
				{
					next = map[next];
				}
				if(!visited[next])
				{
					q.push({next,count+1});
					visited[next] = true;
				}
			}
			
		}
		
	}
	
}
int main(void)
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N+M;i++)
	{
		int a,b;
		cin >> a >> b;
		map[a] = b;
	}
	game(1,0);
	return 0;
}
