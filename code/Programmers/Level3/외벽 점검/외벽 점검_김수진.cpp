#include <bits/stdc++.h>

using namespace std;

int result = 0;
int chkWeak = 0;

void dfs(int start, deque<int> dq, vector<int> dist, int num){
    result++;
    int end = dq[start] + dist[num];
    
    int i = 0;
    chkWeak++;
    
    while(dq[start+i+1]<=end){
        i++;
        chkWeak++;
        if(start+i+1 == dq.size()-1){
            return;
        }
        
    }
    
    if(chkWeak >= dq.size()){
        return;
    }
    
    
    if(num==dist.size()-1){
        result = 10;
        return;
    }
    dfs(start+i, dq ,dist, num+1);
}

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 10;
    sort(dist.begin(), dist.end(),greater<int>());
    
    deque<int> dq;
    for(int i=0; i<weak.size() ; i++){
        dq.push_back(weak[i]);
    }
    
    for(int i = 0; i < dq.size(); i++){
        result = 0;
        chkWeak = 0;
        dfs(0,dq,dist,0);
        answer = min(answer, result);
        int a = dq.front();
        a = a+n-1;
        dq.push_back(a);
        dq.pop_front();
    }
    if(answer==10)  return -1;
    
    return answer;
}
