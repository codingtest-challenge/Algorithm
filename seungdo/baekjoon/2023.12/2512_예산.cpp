//boj_2512_¿¹»ê 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int N,M;
	int result=0;
	int sum=0;
	int start,end;
	vector<int> money;
    cin >> N;
    for(int i=0;i<N;i++)
	{
        int temp;
        cin>>temp;
        money.push_back(temp);
    }
    cin>> M;
    sort(money.begin(),money.end());
    start=0;
    end=money[N-1];
    
    while(start<=end)
	{
        sum=0;
        int mid = (start+end)/2;
        for(int i=0;i<N;i++)
		{
            sum = sum + min(money[i],mid);
        }
        if(M>=sum)
		{
            result=mid;
            start=mid+1;
        }
		else
		{
            end=mid-1;
        }
    }

    cout << result;
}
