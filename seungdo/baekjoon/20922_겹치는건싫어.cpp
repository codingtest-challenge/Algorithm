//BOJ 20922 °ãÄ¡´Â°Ç ½È¾î 
#include <iostream>
#include <deque>
using namespace std;
int count[100001];
deque<int> dq;
int main()
{
	ios::sync_with_stdio(false);      
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K,a;
    int cnt=0;
	int ans=0;
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
    	cin >> a;
    	count[a] = count[a]+1;
    	if(dq.empty())
		{
			dq.push_back(a);
		}
    	else
    	{
    		if(count[a]<=K)
    		{
    			dq.push_back(a);
			}
			else
			{
				int temp = -1;
	    		while(temp != a && !dq.empty())
	    		{
	    			temp = dq.front();
	    			dq.pop_front();
	    			count[temp] = count[temp] - 1;
				}
				dq.push_back(a);
			}
		}
		cnt = dq.size();
		/*
		deque<int>::iterator iter;
		for (iter = dq.begin(); iter != dq.end(); iter++)
		{
			cout << *iter << " ";
		}
		cout<<endl;
		*/
		
		
		ans = max(ans,cnt);
	}
	cout<< ans;
	return 0;

}
