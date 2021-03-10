#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    
    for (int i = 0; i < answer.size(); i++) {
        char temp = answer[i];
        if (!(temp >= 'a' && temp <= 'z') && !(temp >= '0' && temp <= '9') && !(temp == '-') && !(temp == '_') && !(temp == '.')) {
            answer.erase(i, 1);
            i--;
        }
    }
    
    for(int i=0; i<answer.size()-1; i++){
        if(answer[i]==answer[i+1] && answer[i]=='.'){
            answer.erase(i, 1);
            i--;
        }
    }
    
    if(answer[0]=='.'){
        answer.erase(0,1);
    }
    if(answer.back()=='.'){
         answer.pop_back();
    }

    if(answer.empty()) {
        answer.push_back('a');
    }
    
    if(answer.size()>=16){
        answer.erase(15, answer.size() - 15);
    }
    
    if(answer.back()=='.'){
         answer.pop_back();
    }
    
    while(answer.size() <3 ){
        answer.push_back(answer.back());
    }
    
    return answer;
}
