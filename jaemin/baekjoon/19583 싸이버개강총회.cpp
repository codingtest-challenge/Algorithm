//19583 싸이버개강총회

#include <iostream>
#include <map>
using namespace std;

int main(){
    string s, e, q;
    int cnt = 0;
    string time, name;
    map<string, int> m;

    cin>>s>>e>>q;

    while(cin>>time>>name){
        if(m.find(name) != m.end()){
            if(time >= e && time <= q){
                m[name]++;
                if(m[name] == 2) cnt++;
            }
        }
        else{
            if(time <= s){
                m[name] = 1;
            }
        }
    }

    cout<<cnt<<endl;

    return 0;
}