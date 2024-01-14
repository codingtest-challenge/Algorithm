//boj 20920 영단어 암기는 괴로워 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map> 
#include <stdio.h>
using namespace std;

bool compare(pair<int,string>a, pair<int,string>b)
{
	if(a.first == b.first) //빈도수가 같으면 
	{
		if(a.second.length() == b.second.length()) 	//길이도 같으면 
			return a.second < b.second; 			// 사전 오름차순 
		else return a.second.length() > b.second.length(); //길이 다르면 내림차순 
	}
	else return a.first > b.first; 
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N,M;
	cin >> N >> M;
	map<string,int> voca;
	
	for(int i=0;i<N;i++)
	{
		string temp;
		cin >> temp;
		if(temp.size() < M) continue;
		voca[temp]++;
	}
	
	vector<pair<int, string> > book;
	for(auto w : voca)
	{
		book.push_back({w.second,w.first});
	}
	
	sort(book.begin(),book.end(), compare);
	for(auto w : book)
	{
		cout << w.second << '\n';
	}
}
