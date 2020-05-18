 #include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    /* 효율성 조진 코드 
    int l = 0; 
    for(int i=0;i<n;i++){
        int max = max_element(works.begin(), works.end()) - works.begin();
        works[max]--;
        
    }
    for(int i=0; i<works.size();i++){
        if(works[i]>=1){
            answer += works[i]*works[i];
        }
    }*/
    priority_queue<int> q;
    for(int i : works){
        q.push(i);
    }
    for(int i=0; i<n;i++){
        int a = q.top();
        if(a>0){
            a -= 1;
            q.pop();
            q.push(a);   
        }
    }
    for(int i=0; i<works.size();i++){
        int a = q.top();
        answer += a*a; 
        q.pop();
    }
    return answer;
}
