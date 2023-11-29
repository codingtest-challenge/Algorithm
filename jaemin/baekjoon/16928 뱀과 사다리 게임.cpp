// 16928 뱀과 사다리 게임

#include <iostream>
#include <map>
#include <queue>
using namespace std;


int sb[101];
int arr[101];

void bfs(int *arr){
    queue <int> q;
    q.push(1);
    arr[1] = 0;

    while(!q.empty()){
        int x = q.front();
        q.pop();


        if(x==100){
            cout<<arr[x]<<"\n";
            break;
        }/*
        1 1
        13 99
        8 7
        */
        for(int i=1; i<=6; i++){
            int nxt = x + i;
            if(nxt <= 100){
                if(sb[nxt] != 0){ //뱀이나 사다리가 있으면
                    arr[nxt] = arr[x] + 1;
                    int k = sb[nxt];
                    if(arr[k] == 0 || arr[k] > arr[nxt]){
                        arr[k] = arr[nxt];
                        q.push(k);
                    }
                } 

                else{
                    if(arr[nxt] == 0){
                        arr[nxt] = arr[x] + 1;
                        q.push(nxt);
                    }
                }
            }

        }

    }
}

int main(){
    int n, m;   

    cin>>n>>m;


    for(int i=0; i<n+m; i++){
        int x, y;
        cin>>x>>y;
        sb[x] = y;
    }


    
    bfs(arr);


    return 0;
}