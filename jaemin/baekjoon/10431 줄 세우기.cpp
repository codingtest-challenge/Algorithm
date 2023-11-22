// 10431 줄 세우기

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t;

    cin>>t;

    for(int s=1; s<=t; s++){
        int n;
        int res = 0;
        vector<int> v;
        vector<int> seq;

        cin>>n;

        for(int i=0; i<20; i++){
            int x;
            cin>>x;
            v.push_back(x);
        }


        for(int i=0; i<20; i++){
            int x = v[i];
            int pos = 0;
            bool check = 0;
    
            for(int j=0; j<seq.size(); j++){
                if(seq[j] > x){
                    pos = j;
                    seq.insert(seq.begin()+j, x);
                    check=1;
                    break;
                }
            }
            if(check==0){
                seq.push_back(x);
            }
            else{
                res += seq.size() - pos - 1;

            }
        }

     

        cout<<s<<" "<<res<<"\n";
    }

    return 0;
}