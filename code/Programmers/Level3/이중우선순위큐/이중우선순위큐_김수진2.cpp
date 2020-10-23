#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(int i=0; i<operations.size(); i++){
        if(operations[i].substr(0,1)=="I"){
            dq.push_back(stoi(operations[i].substr(2,operations[i].size()-1)));
            sort(dq.begin(),dq.end());
        }else if(operations[i].substr(0,1)=="D"){
            if(dq.empty()) continue;
            if(operations[i].substr(2,1)=="-"){
                dq.pop_front();
            }else{
                dq.pop_back();
            }
        }
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}

/*

테스트 1 〉	통과 (0.02ms, 3.96MB)
테스트 2 〉	통과 (0.02ms, 3.94MB)
테스트 3 〉	통과 (0.02ms, 3.96MB)
테스트 4 〉	통과 (0.02ms, 3.97MB)
테스트 5 〉	통과 (0.02ms, 3.96MB)
테스트 6 〉	통과 (0.02ms, 3.96MB)

*/
