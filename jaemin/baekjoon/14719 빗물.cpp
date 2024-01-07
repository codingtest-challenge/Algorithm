// 14719 빗물

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int h, w;
    int s, e;
    int sum = 0;
    vector<int> v;
    cin>>h>>w;

    for(int i=0; i<w; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }


    for(int i=1; i<w; i++){
        int l=0, r=0;

        
        for(int j=0; j<i; j++){
            l = max(l, v[j]);
        }

        for(int j=i+1; j<w; j++){
            r = max(r, v[j]);
        }
        //cout<<i<<" "<<l<<" "<<r<<" "<<(min(l, r) - v[i])<<endl;

        if(l!=0 && r!=0){
            if((min(l, r) - v[i]) > 0)
                sum += (min(l, r) - v[i]);
        }
    }

    cout<<sum<<endl;

    return 0;
}