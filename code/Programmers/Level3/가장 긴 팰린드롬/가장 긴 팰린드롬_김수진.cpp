#include <bits/stdc++.h>
using namespace std;

int answer = 0;

void solve(char a,int i, string s){
    int index = s.rfind(a);
    if(index==-1){
        return; 
    }
    int mid = (index)/2;
    for(int j=0;j<mid+1; j++){
        if(s[j]!=s[index-j]){
            string ss= s.substr(i,index);
            solve(a,0,ss);
            return;   
        }  
    }
    int answer2 = index+1;
    
    
    answer = max(answer,answer2);
    return;
}

int solution(string s)
{
    
    for(int i=0; i<s.size(); i++){
        if(answer>s.size()-i){
            break;
        }
        char a = s[i];
        solve(a,i,s);
    }
    
    return answer;
}
