#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> student(n,1);
    
    for(int i=0; i<lost.size(); i++){
        student[lost[i]-1]--;
    }
    for(int i=0; i<reserve.size(); i++){
        student[reserve[i]-1]++;
    }
    
    for(int i=0; i<n; i++){
        if(student[i]==0 && student[i+1]==2 && i!= n-1){
            student[i]++;
            student[i+1]--;
        }else if(student[i]==0 && student[i-1]==2 && i!=0){
            student[i]++;
            student[i-1]--;
        }
    }
    
    for (int i = 0; i <n; i++) {
        if (student[i]>0) {
            answer++;
        }
    }
    
    return answer;
}
