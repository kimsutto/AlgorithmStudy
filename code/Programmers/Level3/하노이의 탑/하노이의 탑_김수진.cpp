#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void hanoi(int n, int start, int end, int via){
    if(n==1)
        answer.push_back({start,end});
    else{
        hanoi(n-1,start,via,end);
        answer.push_back({start,end});
        hanoi(n-1,via,end,start);
    }
}

vector<vector<int>> solution(int n) {
    if(n==1){
        answer.push_back({1,3});
        return answer;
    }
    hanoi(n, 1,3,2);
    
    return answer;
}
