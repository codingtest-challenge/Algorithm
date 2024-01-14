// 14888 연산자 끼워넣기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> oper;
int max_sum = -1000000001;
int min_sum = 1000000001;

void dfs(int sum, int idx, int n){
    if(idx == n){
        if(sum > max_sum) max_sum = sum;

        if(sum < min_sum) min_sum = sum;

        return ;
    }

    for(int i=0; i<4; i++){
        
        if(oper[i] > 0){
            oper[i]--;
            
            if(i==0) dfs(sum + v[idx], idx+1, n);

            else if(i==1) dfs(sum - v[idx], idx+1, n);

            else if(i==2) dfs(sum * v[idx], idx+1, n);

            else dfs(sum / v[idx], idx+1, n);

            oper[i]++;
        }
    }
}

int main(){
    int n;

    

    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0; i<4; i++){
        int x;
        cin>>x;
        oper.push_back(x);
    }




    dfs(v[0], 1, n);

    cout<<max_sum<<"\n"<<min_sum<<"\n";
    
    return 0;

}