// 20922 겹치는 건 싫어

#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int main(){
    int n, k;
    int cnt=0, res=0; 
    int arr[200001] = {0,};
    queue<int> q;
    
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;

        q.push(x);
        arr[x]++;

        if(arr[x] > k){
            int size = q.size()-1;
            res = max(res, size);
            while(!q.empty()){
                int a = q.front();
                q.pop();
                arr[a]--;
                if(arr[x] <= k) break;
            }
        }
        else{
            int size = q.size();
            res = max(res, size);
        }
    }

    cout<<res<<endl;

    

    return 0;
}