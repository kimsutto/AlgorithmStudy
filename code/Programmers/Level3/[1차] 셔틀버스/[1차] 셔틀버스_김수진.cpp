#include <bits/stdc++.h>

using namespace std;
vector<int> times;
queue<int> q;
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int start = 9*60;
    for(int i=0; i<timetable.size(); i++){
        int h = stoi(timetable[i].substr(0,2))*60;
        int m = stoi(timetable[i].substr(3,2));
        times.push_back(h+m);
    }
    sort(times.begin(),times.end());
    for(auto i : times){
        q.push(i);
    }
    
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<m; j++){
            if(start>=q.front())
                q.pop();
            else
                break;
        }
        start += t;
    }
    int i=0;
    for(i; i<m-1; i++){
        if(start>=q.front()) q.pop();
        else break;
    }
    
    int hh, mm;
    if(!q.empty()&&q.front()>start){
        hh = start/60;
        mm = start%60;
    }
    else if(i==m-1&&!q.empty()){
        hh = ((q.front()) -1)/60;
        mm = ((q.front()) -1)%60;
    }else{
        hh = start/60;
        mm = start%60;
    }
    
    if(hh<10) answer += '0' +  to_string(hh) + ':';
    else answer += to_string(hh) + ':';
    
    if(mm<10) answer += '0' + to_string(mm);
    else answer += to_string(mm);
    
    return answer;
}
