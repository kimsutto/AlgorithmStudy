#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare (int i, int j){
    return i>j;
}

vector<int> solution(vector<int> arr) {
    vector<int> answer(arr);
    
    if(arr.size() == 1){
        answer.clear();
        answer.push_back(-1);
    }else{
       answer.erase(min_element(answer.begin(), answer.end()));
    }
    return answer;
}
