
#include <bits/stdc++.h>

using namespace std;

vector<string> tokenize(const string& data, const char delimiter=' '){
    vector<string> result;
    string token;
    stringstream s(data);
    
    while(getline(s, token, delimiter)){
        result.push_back(token);
    }
    return result;
}

int solution(vector<string> id_list, int k) {
    int answer = 0;
    
    map<string, int> hash;
    vector<string> tok;
    
    for(int i=0; i<id_list.size();i++){
        vector<string> t = tokenize(id_list[i],' ');
        sort(t.begin(),t.end());
        t.erase(unique(t.begin(),t.end()), t.end());
        
        for(auto e : t){
            tok.push_back(e);
        }
    }
    for(int j=0; j<tok.size(); j++){
        hash[tok[j]]++;
    }
    
    for(auto i : hash){
        if(i.second >= k){
            answer += k;
        }else {
            answer += i.second;
        }
    }
        
    return answer;
}