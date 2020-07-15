#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {2,1,2,3,2,4,2,5};
    vector<int> C = {3,3,1,1,2,2,4,4,5,5};
        
    vector<int> they(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == A[i%A.size()]) they[0]++;
        if(answers[i] == B[i%B.size()]) they[1]++;
        if(answers[i] == C[i%C.size()]) they[2]++;
    }
    
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }
    
    return answer;
}
