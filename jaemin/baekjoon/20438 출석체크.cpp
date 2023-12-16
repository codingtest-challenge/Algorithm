//20438 출석체크

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    int n, k, q, m;
    vector<int> qs; // 지환이에게 출석코드 받을 학생
    int arr[5003];
    cin>>n>>k>>q>>m;

    fill_n(arr, 5003, 1);
    arr[2] = 0;

    // 졸고 있는 학생 번호
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        arr[x] = -1;
    }

    // 출석코드 받은 학생 번호
    for(int i=0; i<q; i++){
        int x;
        cin>>x;

        if(arr[x] != -1)
            qs.push_back(x);
        
    }


    for(int i=0; i<qs.size(); i++){
        int x = qs[i];
        if(arr[x] == -1) continue;
        int j = 2;
        int z = x;

        while(z <= n+2){
            if(arr[z] != -1){
                arr[z] = 0;
            }

            z = x * j;
            j++;
        }
    }



    for(int i=3; i<=n+2; i++){
        arr[i] = abs(arr[i]) + arr[i-1];
    }

    for(int i=0; i<m; i++){
        int s, e;
        cin>>s>>e;
        cout<<arr[e] - arr[s-1]<<"\n";
    }

    return 0;
}