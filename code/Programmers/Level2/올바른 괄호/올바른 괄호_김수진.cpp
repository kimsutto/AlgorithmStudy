#include<bits/stdc++.h>

using namespace std;

bool solution(string s){
    bool answer = true;
    
    stack<char> st;
    for(char c : s){
        if(c=='(') st.push('(');
        else if(c==')'){
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }else return false;
        }
    }
    if(!st.empty()) return false;
    return answer;
}
