#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n, mxm;
    vector<long long> v;

    cin>>n;
    
    for(int i=0; i<n; i++){
        long long x;

        cin>>x;

        v.push_back(x);
    }

    cin>>mxm;

    sort(v.begin(), v.end());

    long long mid = (v[0] + v[n-1])/2;

    long long sum = 0;
    for(int i=0; i<n; i++){
        if(v[i] <= mid) sum += v[i];
        else sum += mid;
    }

    if(sum > mxm){
        while(1){
            sum = 0;
            mid--;
            for(int i=0; i<n; i++){
                if(v[i] <= mid) sum += v[i];
                else sum += mid;
            }
            if(sum <= mxm) break;
        }
    }


    else if(sum < mxm){
        while(1){
            if(mid==v[n-1]) break;
            sum = 0;
            mid++;
            for(int i=0; i<n; i++){
                if(v[i] <= mid) sum += v[i];
                else sum += mid;
            }
            if(sum >= mxm) {
                if(sum > mxm) mid--; 
                break;
            }
        }
    }
    
    cout<<mid<<endl;

    return 0;
}