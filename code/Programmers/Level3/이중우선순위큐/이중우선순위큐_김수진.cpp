#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, less<int>> q; //높은 순 
    priority_queue< int, vector<int>, greater<int>> t; //낮은순 
    int cnt =0;
    for(int i=0; i<operations.size(); i++){
         if(i>0&&cnt==0){
                while(!q.empty()){
                    q.pop();
                }
                while(!t.empty()){
                    t.pop();
                }
        };
        if(operations[i].substr(0,1)=="I"){
            cnt++;
            q.push(stoi(operations[i].substr(2,operations[i].size()-1)));
            t.push(stoi(operations[i].substr(2,operations[i].size()-1)));
        }else if(operations[i].substr(0,1)=="D"){
            if(cnt==0){
                continue;
            };
            cnt--;
            if(operations[i].substr(2,1)=="-"){
                t.pop();
            }else{
                q.pop();
            }
        }
    }
    //빈 경우 
   
    if(cnt<=0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(q.top());
        answer.push_back(t.top());
    }
    
    return answer;
}

/*

테스트 1 〉 통과 (0.02ms, 3.73MB)
테스트 2 〉	통과 (0.02ms, 3.91MB)
테스트 3 〉	통과 (0.02ms, 3.96MB)
테스트 4 〉	통과 (0.01ms, 3.94MB)
테스트 5 〉	통과 (0.02ms, 3.96MB)
테스트 6 〉	통과 (0.02ms, 3.96MB)


*/
