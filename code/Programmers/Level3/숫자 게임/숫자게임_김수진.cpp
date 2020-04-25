#include<bits/stdc++.h>

using namespace std;



int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int jj= 0;
    for(int i=0; i<B.size();i++){
        for(int j=jj; j<B.size(); j++){
            if(A[i]<B[j]){
                answer++;
                if(j==B.size()){
                    return answer;
                }
                jj=j+1;
                break;
            }
        }
    }
    return answer;
}