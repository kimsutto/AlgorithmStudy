#include <bits/stdc++.h>

using namespace std;

int result = 0;
int chkWeak = 0;

void dfs(int start, deque<int> dq, vector<int> dist, int num){
    result++;
    int end = dq[start] + dist[num];
    chkWeak++;
    int i = start+1;
    for(; i<dq.size(); i++ ){
        if(dq[i] > end)
            break;
        chkWeak++;
    }
    if(chkWeak>=dq.size()){
        return;
    }
    if(num==dist.size()-1){
        result = 10000;
        return;
    }else{
        dfs(i, dq ,dist, num+1);
        return;
    }
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10000;
    deque<int> dq;
    for(int i=0; i<weak.size() ; i++){
        dq.push_back(weak[i]);
    }
    
    

    
    do{
        for(int i = 0; i < dq.size(); i++){
            result = 0;
            chkWeak = 0;
            dfs(0,dq,dist,0);
        
            answer = min(answer, result);
            int a = dq.front();
            a = a+n;
            dq.push_back(a);
            dq.pop_front();
        }
    }while(next_permutation(dist.begin(),dist.end()));
        
    if(answer>=10)  return -1;
    
    return answer;
}
