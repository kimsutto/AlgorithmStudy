#include <string>
#include <vector>
#include <iostream>
using namespace std;
 
string solution(string s) 
{
    string answer = "";
   
    int count = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            count = 0;
            answer += s[i];
            continue;
        }
        else{
            if(count % 2 == 0){
                if('A' <= s[i] && s[i] <= 'Z'){
                    answer += s[i];
                } else{
                    answer += s[i]-'a'+'A';
                }
            }
            else{
                if('a' <= s[i] && s[i] <= 'z'){
                    answer += s[i];
                }
                else{
                    answer += s[i]-'A'+'a';
                }
            }
        }
        count++;
    }
    
    return answer;
}
