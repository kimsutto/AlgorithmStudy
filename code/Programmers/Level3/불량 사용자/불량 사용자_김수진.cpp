#include<bits/stdc++.h>

using namespace std;
int answer = 0;
vector<vector<string>> a;
set<string> s;
set<string>::iterator iter;
set<set<string>> sss;


void dfs(int in){
    if(in == a.size()){
        sss.insert(s);
        return ;
    }
    for (int i= 0; i<a[in].size();i++){
        if(s.count(a[in][i])==0){
            s.insert(a[in][i]);
            dfs(in+1);
            s.erase(a[in][i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    int size = banned_id.size();
    
    
    for(int j=0; j<banned_id.size(); j++){
         vector<string> aa;
        for(int i=0; i<user_id.size();i++){
            if(user_id[i].size()==banned_id[j].size()){
                for(int k=0; k<user_id[i].size();k++){
                    if(!(banned_id[j][k]=='*')&&!(user_id[i][k]==banned_id[j][k])){
                        break;
                    }    
                    if(k==user_id[i].size()-1){
                        aa.push_back(user_id[i]);
                    }   
                }
            }
        }
        a.push_back(aa);
    }
    
    dfs(0);
                                     
    return sss.size();
}