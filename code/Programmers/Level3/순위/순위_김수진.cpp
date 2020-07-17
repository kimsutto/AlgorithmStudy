#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool graph[101][101] = {false,};
    
    for(int i=0; i<results.size() ; i++){
        graph[results[i][0]][results[i][1]]=true;
    }
    
    for(int i=1; i<=n ; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(graph[j][i] && graph[i][k]){
                    graph[j][k]=true;
                }
            }
        }
    }
    
    for(int i=1; i<=n; i++){
        int sum = 0;
        for(int j=1; j<=n; j++){
            if (graph[i][j] || graph[j][i]){
                sum++;
            }
        }
        if(sum==n-1){
            answer++;
        }
    }
    return answer;
}
