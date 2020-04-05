#include string
#include vector

using namespace std;

void dfs(int v, bool visited[], vectorvectorint computers){
    visited[v]=true;
    
    for(int i=0; icomputers.size(); i++){
        if(visited[i]==false && computers[v][i]==1){
            dfs(i,visited,computers);
        }
    }
}

int solution(int n, vectorvectorint computers) {
    int answer = 0;
    int len = computers.size();
    bool visited[len];
    
   for(int i = 0; i len; i++){
           visited[i] = false;
      }
        
    for(int i = 0; i  computers.size(); i++){
        if(visited[i] == false){
            answer++;
            dfs(i, visited, computers);
        }            
    }
        
    return answer;
    
}

