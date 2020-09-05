#include <bits/stdc++.h>

using namespace std;

vector<string> answer; 
vector<string> ans; 
bool visited[10000];
string last;

bool dfs(vector<vector<string>> tickets, string a, int b){
    ans.push_back(a);
    if(b==tickets.size()){
        answer = ans; 
        return true;
    }
    
    for(int i=0; i< tickets.size() ; i++){
        if(tickets[i][0]==a && !visited[i]){
            visited[i] = true;
            last = tickets[i][1];
            if(dfs(tickets,last,b+1)) return true;
            visited[i]= false;
        }   
    }
    ans.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    dfs(tickets, "ICN", 0);
    
    
    return answer;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    //H , I , J 
    dfs(tickets, 0);
    
    
    return answer;
}
