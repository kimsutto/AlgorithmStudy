#include <bits/stdc++.h>

using namespace std;

//나중에 이분탐색써서 풀어보기.. 

int solution(vector<int> budgets, int M) {
    int answer = 0;
    long long sum=0;
    int size = budgets.size();
    sort(budgets.begin(), budgets.end());
    
    for (int i = 0; i < size; i++) {
        sum += budgets[i];
    }
    
    if(sum<=M){
       return budgets[size-1];
    }
    
    int a = M/size;
    
    for(int i=0; i<budgets.size();i++){
        if(a>budgets[i]){
            M -= budgets[i];
            size--;
            a=M/size;
        }
        else{
            break;
        }
    }
    
    answer = a;
    return answer;

}