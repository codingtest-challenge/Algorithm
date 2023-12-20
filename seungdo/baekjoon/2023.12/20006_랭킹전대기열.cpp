//20006_랭킹전대기열 
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Player{
	string name;
	int level;
};
bool compare(const Player& a, const Player& b)
{
	return a.name<b.name;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	map<int ,vector<Player> > rooms;
	
	int p,m;
	cin >> p >> m;

	Player player;
	int index = 0;
	bool flag = false;
	for(int i=0;i<p;i++)
	{
		cin >> player.level >> player.name;
		flag = false;
		
		if(rooms.size() == 0) //방이 비었을때 
		{
			rooms[index++].push_back(player);
			continue;
		}
		
		for(auto it = rooms.begin(); it!=rooms.end(); it++)
		{
			if(it->second.size() >= m) continue;
			if(it->second[0].level - 10 <= player.level && it->second[0].level + 10 >= player.level)
			{
                it->second.push_back(player);
                flag = true;
                break;
        	}
        }
		if(flag) continue;
		rooms[index++].push_back(player);
	}
	
	for(auto it = rooms.begin();it!=rooms.end();it++)
	{
		if(it->second.size()>=m) cout<<"Started!\n";
		else cout<<"Waiting!\n";
		
		sort(it->second.begin(),it->second.end(),compare);
		for(int i=0; i < it->second.size();i++)
		{
			cout<<it->second[i].level<<" "<<it->second[i].name<<"\n";
		}
	}
	return 0;
}
