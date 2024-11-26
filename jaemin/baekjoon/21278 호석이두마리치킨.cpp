// 21278 G5 호석이두마리치킨

/*
    플로이드 워셜로 경로의 거리를 미리 다 구해놓고
    조합을 통해서 2개를 뽑아서 비교

    N = 100
    플로이드 워셜로 경로의 거리를 구하는 비용
    100 * 100 * 100 -> 1000000

    조합을 통해 2개를 뽑아서 비교 100C2 * 100
    990000

    총 1990000
*/

#include <iostream>
#include <math.h>

using namespace std;

const int INF = 1000000000;

int N, M;
int arr[101][101];
int picked[2];
int minRes = INF;
int resX, resY;

void combi(int cnt, int idx){
    if(cnt == 2){

        int sum = 0;
        // cout<<picked[0]<<" "<<picked[1]<<endl;

        int x = picked[0];
        int y = picked[1];
        for(int i=1; i<=N; i++){
            if(i != x && i != y){
                sum += min(arr[i][x], arr[i][y]) * 2;
            }
        }
        if(sum < minRes){
            minRes = sum;
            resX = x;
            resY = y;
        }
        minRes = min(minRes, sum);

        return ;
    }

    for(int i=idx; i<=N; i++){
        picked[cnt] = i;
        combi(cnt+1, i+1);
    }
}


int main() {

    cin>>N>>M;

    fill(arr[0], arr[101], INF);

    for(int i=0; i<M; i++){
        int x, y;
        cin>>x>>y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
            }
        }
    }

    combi(0, 1);

    cout<<resX<<" "<<resY<<" "<<minRes;

    return 0;
}