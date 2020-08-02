#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int& a, int& b){
    return a > b ? true : false;
}

bool pairCompare(const pair<int,float> &a, const pair<int, float> &b){
    if(a.second > b.second) return true;
    else if(a.second == b.second ){
        if(a.first < b.first) return true;
        else return false;
    } else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer; 
    vector<pair<int,float>> rate;
 
    sort(stages.begin(), stages.end(),compare);
    
    for(int n=1; n<=N; n++){
        int clear=0;
        int fail=0;
   
        for(int i=0; i<stages.size(); i++){
            if(stages[i] < n) break;
            if(stages[i] >= n) clear++;
            if(stages[i] == n) fail++;
        }
        
        if(fail==0) rate.push_back(make_pair(n,0));
        else rate.push_back(make_pair(n, (float)fail/clear));
        
    }
    
    sort(rate.begin(), rate.end(), pairCompare);
    
    for(int i = 0; i < N; i++){
        answer.push_back(rate[i].first);
    } 
    
    return answer;
}
