#include <string>
#include <bits/stdc++.h>

using namespace std;

vector<int> node[20001];
bool visited[20001];
int dist[20001] = {0,}; 
int m = 1;

void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        visited[x] = true;
        q.pop();
         for (int i = 0; i < node[x].size(); i++) {
           int y = node[x][i];
           if (visited[y] == false) {
                q.push(y);
                dist[y] = dist[x]+1;
                m = max(m,dist[y]);
                visited[y] = true;
           }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0; i<edge.size(); i++){
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    for(int i=1; i<=n; i++){
        if(dist[i]==m){
            answer++;
        }
    }
    
    return answer;
}
