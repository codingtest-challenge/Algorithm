#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int main()
{
	int N;
	cin >> N;
	for(int i=1;i<=N;i++)
	{
		arr[i] = arr[i-1] + 1;
		if(i>=2) arr[i] = min(arr[i],arr[i-2]+1);
		if(i>=5) arr[i] = min(arr[i],arr[i-5]+1);
		if(i>=7) arr[i] = min(arr[i],arr[i-7]+1);
	}
	cout<<arr[N];
	return 0;
}
