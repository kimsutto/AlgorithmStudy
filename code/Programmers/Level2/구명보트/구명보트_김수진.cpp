#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    for(int i=0; i<people.size();){
        if(people[i]+people[people.size()-1]<=limit)
            i++;
        people.pop_back();
        answer++;
    }
    return answer;
}
