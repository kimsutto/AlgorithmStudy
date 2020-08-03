#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(1){
        
        if(n%3==1)answer.push_back('1');
        else if(n%3==2) answer.push_back('2');
        else {
            answer.push_back('4');
            n--;
        }
        n = n/3;
        if(n<1) break;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
