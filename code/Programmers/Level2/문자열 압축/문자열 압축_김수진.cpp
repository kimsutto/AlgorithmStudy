#include <bits/stdc++.h>

using namespace std;

string str;

int solve(int num, int size)
{
    string result = ""; int count = 1;
    for(int i=0; i<size; i+=num)
    {   
        if(i+num > size || str.substr(i,num)!=str.substr(i+num,num)){
            if(count>1) {
                result += to_string(count);
            }
            result += str.substr(i,num);
            count = 1;
        }else{
            count++;
        }
    }
    return result.size();
}

int solution(string s) {
    str = s;
    int answer = 1000;
    if(s.size()==1)
        return 1;
    int size = s.size()/2;
    
    for(int i=1; i<=size; i++){
        int result = solve(i,s.size());
        answer = min(answer, result);
    }
    
    return answer;
}
