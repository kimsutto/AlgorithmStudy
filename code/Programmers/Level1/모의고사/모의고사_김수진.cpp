#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //1번 
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt[3] = {0,};
    
    for(int i=0; i<answers.size();i++){
        if(answers[i]==a[i%5])  cnt[0]++;
        if(answers[i]==b[i%8])  cnt[1]++;
        if(answers[i]==c[i%10]) cnt[2]++;
    }
    
    int maxc = max(cnt[0], max(cnt[1],cnt[2]));
    if(cnt[0]==maxc) answer.push_back(1);
    if(cnt[1]==maxc) answer.push_back(2);
    if(cnt[2]==maxc) answer.push_back(3);
    
    
    return answer;
}
