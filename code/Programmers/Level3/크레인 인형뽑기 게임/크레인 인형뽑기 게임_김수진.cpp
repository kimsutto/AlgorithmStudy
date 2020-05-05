#include<bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board.size();
    vector<vector<int>> bo= board;
    stack<int> s;
    s.push(10000);
    
    for(int i=0; i<moves.size();i++){
        int aa = moves[i]-1;
        int a;
        
        for(int k=0;k<size;k++){
            a = bo[k][aa];
            if(a!=0){
                bo[k][aa]=0;
                break;
            }
        }
        if(a!=0){
        if(a==s.top()){
            s.pop();
            answer+=2;
        }else{
            s.push(a);
        }
        }
    }
    
    return answer;
}