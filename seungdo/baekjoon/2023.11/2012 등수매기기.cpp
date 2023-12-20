//boj 2012 등수매기기 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	vector<int> v;
	long long ans=0LL;
	cin >> N;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++)
	{
		int temp = (v[i] - (i+1));
		if(temp < 0) temp*=-1;
		ans += temp;
	}
	cout << ans << endl;
}
