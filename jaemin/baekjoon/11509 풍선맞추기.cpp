// 11509 풍선맞추기

#include <iostream>
using namespace std;

int main(){
    int n;
    int h[100000] = {0,};
    int cnt = 0;
   
   cin>>n;

    for(int i=0; i<n; i++){
        cin>>h[i];
    }

    for(int i=0; i<n; i++){
        int x = h[i];
        if(h[i] != 0){
            h[i] = 0;
            x--;
            for(int j=i+1; j<n; j++){
                if(h[j] == x){
                    h[j] = 0;
                    x--;
                }
            }

            cnt++;
        }
    }

    cout<<cnt<<endl;





    return 0;
}