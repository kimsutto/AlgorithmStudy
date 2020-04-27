#include<bits/stdc++.h>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    int r = 0;
    
    for(int i=0; i<arrangement.size();i++){
        if(arrangement[i] == ')'){
          s.pop();
          if(arrangement[i-1]==')'){
              answer++;
          }else{
             answer += s.size(); 
          }
        }else{
          s.push(arrangement[i]);  
        }
    }
    return answer;
}
