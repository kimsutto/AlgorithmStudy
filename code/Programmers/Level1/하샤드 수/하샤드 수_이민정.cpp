#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int sum=0;
    int y = x;
    
    while(y>=1){
        sum += y%10;
        y /= 10;
    }
    
    if(x%sum==0){
        answer = true;
    }
    return answer;
}
