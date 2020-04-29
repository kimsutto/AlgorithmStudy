#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<int> answer2;
    
    answer2.push_back(0);
    if(n==1){
        return answer2;
    }
    for(int i=1; i<n; i++){
            answer.push_back(0);
        for(int j=0;j<answer2.size();j++){
            answer.push_back(answer2[j]);
            answer.push_back((j+1)%2);
        }
        if(i==n-1){
            return answer;
        }else{
            answer2.clear();
            answer2 = answer;
            answer.clear();
        }
    }
    return answer;
}