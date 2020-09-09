#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;
    bool num[1000000];
 
    
    for(int i = 2; i <= n; i++) {
        if(num[i] == false){
            for(int j = i*2; j <= n; j+=i) {
                num[j] = true;
            }   
        }
    }
    
    for(int i = 2; i <= n; i++) {
        if(num[i] == false) 
            answer++;
    }
    return answer;
}

