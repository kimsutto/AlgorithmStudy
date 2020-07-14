#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int n;
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i]=="Kim"){
            n = i;
            break;
        }
    }
    answer = "김서방은 "+to_string(n)+"에 있다";
    return answer;
}
