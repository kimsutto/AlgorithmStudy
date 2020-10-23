#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights){
    queue<pair<int,int>> q;
    int time = 0;
    int we = weight;
    int i =0;
    while(1){    
        time++;
        if(time - q.front().first == bridge_length)
        {
            we += q.front().second;
            q.pop();
        }
        if(we-truck_weights[i]>=0){
            q.push({time,truck_weights[i]});
            we-=truck_weights[i];
            i++;
        }
        if(i==truck_weights.size()){
            time += bridge_length;
            break;
        }
    }
    
    return time;
}
