#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<long long> num;
    
    int i=0;
    while(n!=0){
        num.push_back(n%10);
        n /= 10;
        i++;
    }
    
    sort(num.begin(),num.end());
    
    for(int i=0; i<num.size(); i++){
        answer += num[i]*pow(10,i);
    }
    
    return answer;
}
