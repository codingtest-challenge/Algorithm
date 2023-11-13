#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int search_max(vector<long long> v, int pos){
    int j = 0;
    int max = 0;
    
    for(int i=pos; i<v.size(); i++){
        if(v[i] > max){
            j = i;
            max = v[i];
        }
    }

    return j;
}

int main(){

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    long long t;

    cin>>t;

    for(int i=0; i<t; i++){
        long long n;
        long long res = 0;
        vector<long long> v;

        cin>>n;

        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        int m = v[n-1];
        for(int j=n-2; j>=0; j--){
            if(v[j] < m){
                res += m - v[j];
            }
            else if(v[j] > m){
                m = v[j];
            }
        }

        cout<<res<<"\n";


    }    


    return 0;
}