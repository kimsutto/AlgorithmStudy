#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer; //가로, 세로 
    int total = brown + yellow; 
    int minH = 3;
    int minW = 0;
    while(1){
        minW = (brown - minH*2)/2 +2;
        if((minW-2)*(minH-2) == yellow)
            break;
        else minH++;
    }
    answer.push_back(minW);
    answer.push_back(minH);
    return answer;
}
