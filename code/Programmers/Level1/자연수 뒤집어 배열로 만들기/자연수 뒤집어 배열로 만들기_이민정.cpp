#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;

    long long ret = n;

    while(1){
        if(ret==0){
            break;
        }
        answer.push_back (ret%10);
        ret = ret/10;
    }

    return answer;
}
