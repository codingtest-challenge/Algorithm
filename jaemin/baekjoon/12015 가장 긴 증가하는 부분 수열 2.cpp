#include <iostream>
#include <vector>
using namespace std;

int main(){
    int arr[100000] = {0, };
    vector<int> res;

    int n;
    int cnt = 0;

    cin>>n;

    for(int i=0; i<n; i++){
       cin>>arr[i]; 
    }

    res.push_back(arr[0]);

    for(int i=1; i<n; i++){
        if(arr[i] > res.back()){
            res.push_back(arr[i]);
        }
        else{
            int idx = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
            res[idx] = arr[i];
        }
    }

    cout<<res.size()<<endl;
   

    return 0;
}