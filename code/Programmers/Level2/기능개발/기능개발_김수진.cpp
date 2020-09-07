#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int,int>> q;
    for(int i = 0; i< progresses.size() ; i++){
        q.push(make_pair(100-progresses[i], speeds[i]));
        
    }
    int i = 0;
    while(!q.empty()){
        int ans = 0;
        if(i!=0){
            q.front().first -= i*q.front().second;
        }
        while(0<q.front().first){
             q.front().first -= q.front().second;
             i++;  
        }
        ans++;
        q.pop();
        
        while((0 >= (q.front().first - (i * q.front().second))) && !q.empty()){
            ans++;
            q.pop();
        }
        answer.push_back(ans);
    }
    
    return answer;
}
