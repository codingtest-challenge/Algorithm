// 달나라 토끼
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long n;
    int arr[100001];
    int idx[4] = {1, 2, 5, 7};
    cin>>n;

    fill_n(arr, 100001, 9999999);
    arr[0] = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++){
            int x = i + idx[j];
            if(x <= n){
                arr[x] = min(arr[x], arr[i]+1);
            }
        }

    }

    cout<<arr[n]<<endl;

    return 0;
}