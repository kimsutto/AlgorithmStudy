#include <bits/stdc++.h>

using namespace std;

vector<string> answer; 
vector<string> ans; 
bool visited[10000];
string last;

void dfs(vector<vector<string>> tickets, int a){
    if(a==tickets.size()){
        answer = ans; 
        return;
    }
    
    for(int i=0; i< tickets.size() ; i++){
        if(ans.size()==0){
            if(tickets[i][0]=="ICN" && !visited[i]){
                ans.push_back(tickets[i][0]);
                ans.push_back(tickets[i][1]);
                last = tickets[i][1];
                visited[i] = true;
                dfs(tickets,a+1);
                visited[i]= false;
            }
        }else if(last==tickets[i][0] && !visited[i]) {
            ans.push_back(tickets[i][1]);
            last = tickets[i][1];
            visited[i] = true;
            dfs(tickets,a+1);
            visited[i] = false;
        }    
    }
    ans.pop_back();
    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    //H , I , J 
    dfs(tickets, 0);
    
    
    return answer;
}
