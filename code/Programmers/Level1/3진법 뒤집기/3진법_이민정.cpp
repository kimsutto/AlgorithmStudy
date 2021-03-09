#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

int solution(int n) {
    stack <int> s;
    int answer = 0;
    int k = 0;
    
    while(n!=0) {
        
        s.push(n%3);
        n = n/3;
        
    }
    
    
    while(!s.empty()){
        answer += s.top()*pow(3, k);
        k++;
        s.pop();
    }
    
    
    return answer;
}
