#include <string>
#include <vector>
using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    for(long long i=1;i<=n;i++){
        if(n/i==i && n%i==0){
            answer = (i+1)*(i+1);
            break;
        }
    }
    
    return answer;
}
