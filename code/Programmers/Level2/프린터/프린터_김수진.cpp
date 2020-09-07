#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    int order[100] ;
    for(int i = 0;  i<priorities.size(); i++){
        q.push(make_pair(priorities[i],i));
        order[i] = priorities[i];
    }
    sort(order, order + priorities.size(),compare);
    int i = 0;
    while(!q.empty()){
        if(q.front().first == order[i]){
            if(q.front().second == location){
                return answer +1;
            }else{
                q.pop();
                i++;
                answer++;
            }
        }else{
            q.push(q.front());
            q.pop();
        }
    }
    return answer;
}
