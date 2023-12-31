#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int x, y;
    
    cin>>x>>y;

    if(x==y){
        cout<<0<<endl;
        return 0;
    }

    int d = y - x;
    int a = sqrt(d);

    if(a*a == d){
        
        cout<<2*a-1<<endl;
    }

    else if(d <= 3){
        cout<<d<<endl;
    }

    else{
        
        int b = 0;
        int i=1;
        while(1){
            
            if((i*i < d) && (i+1)*(i+1) >=d){
                b = i;
                break;
            }
            i++;
        }

        if(d-(b*b) <= b){
            cout<<2*b<<endl;
        }
        else{
            cout<<2*b+1<<endl;
        }
    }

    return 0;   
}