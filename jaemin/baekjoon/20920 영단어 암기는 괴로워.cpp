#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool compare(pair<string, int> &a, pair<string, int> &b){
    // <는 오름차순 
    // >는 내림차순
    
    if(a.second == b.second){ // 1번 조건에서 단어의 개수가 같으면
        if(a.first.length() == b.first.length()){ // 3번 조건 알파벳 사전 오름차순 배치
            return a.first < b.first; // < 오름차순 (문자열에서 오름차순 내림차순은 자동적으로 사전순 정렬)
        }
        else // 2번 조건 단어의 길이가 길수록 앞에 배치 (> 내림차순)
            return a.first.length() > b.first.length();
    }
    // 1번 조건 자주 나오는 단어일수록 앞에 배치
    return a.second > b.second;
}

int main(){
    int n, m;

    //정렬하지 않는 MAP
    unordered_map<string, int> check; // find에서 O(1)의 시간을 가짐

    cin>>n>>m;

    for(int i=0; i<n; i++){
        string input;
        cin>>input;

        if(input.length() >= m){
            if(check.find(input)!=check.end()){
                check[input]++;
            }
            else{
                check[input] = 1;
            }
        }

    }
    
    vector<pair<string,int>> v(check.begin(), check.end());

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<"\n";
    }

    return 0;
}