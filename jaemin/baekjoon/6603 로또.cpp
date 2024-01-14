// 6603 로또

#include <iostream>
#include <vector>
using namespace std;

vector<int> in;
vector<int> comp;

void combi(int idx, int k, int cnt){
    //cout<<cnt<<" "<<idx<<endl;
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout<<comp[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    for(int i=idx; i<k; i++){
        comp.push_back(in[i]);
        combi(i+1, k, cnt+1);
        comp.pop_back();
    }
}

int main(){

    while(true){
        in.clear();
        comp.clear();

        int k;
        cin>>k;

        if(k==0) break;


        for(int i=0; i<k; i++){
            int x;
            cin>>x;

            in.push_back(x);
        }


        combi(0, k, 0);

        cout<<endl;
    }

    return 0;
}