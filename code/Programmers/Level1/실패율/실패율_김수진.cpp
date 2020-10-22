#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,double> a, pair<int,double> b){
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> an;
    sort(stages.begin(),stages.end());
    
    int size = stages.size();
    
    int j = 0;
    for(int i=1; i<=N; i++){
        int cnt = 0; 
        for(j; j<stages.size();j++){
            if(i==stages[j]) cnt++;
            else break;
        }
        if(cnt ==0 || (double)cnt/size ==0.0)
            an.push_back({i,0});
        else
            an.push_back({i,(double)cnt/size}); 
        size -= cnt;
    }
        
    sort(an.begin(),an.end(),cmp);
    
    for(auto i : an){
        answer.push_back(i.first);
    }
    
    return answer;
}
