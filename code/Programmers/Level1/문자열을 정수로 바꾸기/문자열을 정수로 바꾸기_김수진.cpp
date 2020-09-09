#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    //answer = stoi(s);
    int i=0;
    int b = 0;
    if(s[0]=='-'){
        i=1;
        b=1;
    }else if(s[0]=='+'){
        i=1;
    }
    for(; i < s.size(); i++) {
        int num = s[i] - 48;
        answer = answer* 10 + num;
    
    }
    
    if(b==1) {
        answer = -(answer);
    }
    
    return answer;
}
