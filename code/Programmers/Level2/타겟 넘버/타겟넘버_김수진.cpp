#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int n, int s, int p){
    int len = numbers.size();
    
    int num = n;
    int sum = s;
    if(p==0){
        sum += numbers[n];
    }else {
        sum -=numbers[n];
    }
    
    if(len == (n+1)){
        if(sum==target){
            answer++;
            return;
        }else {
            return;
        }
    }
    
    
    dfs(numbers, target, num+1, sum, 0);
    dfs(numbers, target, num+1, sum, 1);
    
    
    
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers,target,0,0,0);
    dfs(numbers,target,0,0,1);
    return answer;
}