#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    for(int i = 0; i < seoul.size(); i++){
        if(seoul[i] == "Kim"){
            answer += to_string(i);
        }
    }
    //answer += to_string(find(seoul.begin(),seoul.end(),"Kim") - seoul.begin());
    answer += "에 있다";
    return answer;
}
