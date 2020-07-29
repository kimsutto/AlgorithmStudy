#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> OR(n);
    
    for(int i=0; i<n; i++){
        OR[i] = (arr1[i] | arr2[i]);
        for(int j=0; j<n; j++){
            if((int)OR[i]/(int)pow(2,n-1-j)==1) answer[i]+='#';
            else answer[i] += ' ';
            OR[i] = (int)OR[i] % (int)pow(2,n-1-j);
        }
    }
    
    return answer;
}
