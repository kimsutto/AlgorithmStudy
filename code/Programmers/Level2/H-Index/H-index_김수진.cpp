#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int h= 0;
    int k= 0;
    sort(citations.begin(),citations.end());
    
    for(int i=0; i< citations.size(); i++){
        h= citations[i];
        k=citations.size() - i;
        if(k<=h){
            answer = k;
            break;
        }
    }
    
    return answer;
}