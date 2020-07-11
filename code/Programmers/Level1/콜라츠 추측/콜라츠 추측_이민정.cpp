#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = static_cast<long long>(num);
    int answer = 0;
    
     while(n != 1){
        if(answer >= 500){
            answer = -1;
            break;
        }
        if(n%2==0) n = n/2;
        else n = 3*n+1;
        answer++;
     }
    
    return answer;
}
