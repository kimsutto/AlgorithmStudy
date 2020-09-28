#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(1);
    answer.push_back(1);
    
    set<string> s;

    string before = words[0];
    s.insert(before);
    
    for(int i=1; i<words.size(); i++){
        if (answer[0] == n) {
            answer[0] = 1;
            answer[1]++;
        }
        else
            answer[0]++;
        
        if(s.count(words[i])>0){
            return answer;
        }
        if(before.substr(before.size()-1,1)!=words[i].substr(0,1)){
            return answer;
        }
        before = words[i];
        s.insert(words[i]);
    }

    answer[0] = 0;
    answer[1] = 0;
    return answer;
}
