#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0; i<s.length(); i++){
        if(s[i]==' ') answer += ' ';
        if('A'<=s[i]&&s[i]<='Z'){
            answer += char(int(s[i]+n-'A')%26+'A');
        }else if('a'<=s[i]&&s[i]<='z'){
            answer += char(int(s[i]+n-'a')%26+'a');
        }
    }
    
    return answer;
}
