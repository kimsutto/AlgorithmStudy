#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
  if(a[1] == b[1])
    return a[0] < b[0];
  else return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int total = 0;
    int jobSize = jobs.size();
    
    sort(jobs.begin(), jobs.end(), cmp);
    
    
     while (!jobs.empty()) {
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][0] <= answer) {
                answer += jobs[i][1];
                total += answer - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            } 
            if (i == jobs.size()-1) answer++;
        }
    }
    
    return total/jobSize;
}
