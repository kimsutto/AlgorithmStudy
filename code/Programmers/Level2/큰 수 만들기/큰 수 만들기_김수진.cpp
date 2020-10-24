#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0; 
    int start = 0; 
    while(1){
        if(cnt==k) break;
        if(start == number.size()-1){
            string answer = "";
            for(int i=0; i<number.size()-k; i++){
                answer += number[i];
            }
            return answer;
        }
        if(number[start]-'0'<number[start+1]-'0'){
            number.erase(start,1);
            cnt++;
            start = 0;
        }else{
            start++;
        }
        
    }
    return number;
}
