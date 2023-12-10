// 29718 실버와 소수는 둘다 S로 시작한다

#include <iostream>
#include <math.h>
using namespace std;

bool prime[5000001];

void primeCheck(int n){
    for(int i=2; i<=n/2; i++){
        if(prime[i]) continue;
        for(int j=2; i*j<=n; j++){
            prime[i*j] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int n;
    int bres = 1;
    int sres = 0;
    char ch = 'b';

    cin>>n;

    primeCheck(n);

    for(int i=2; i<=n; i++){
       if(prime[i]){
            ch = 'b';
            bres++;
       }
       else{
            if(ch=='b'){
                ch = 's';
                bres--;
                sres+=2;
            }
            else{
                ch = 's';
                sres++;
            }
       }
    }

    if(bres < 0) bres = 0;

    cout<<bres<<" "<<sres<<"\n";



    return 0;
}