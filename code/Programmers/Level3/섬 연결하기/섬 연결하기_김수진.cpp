#include <bits/stdc++.h>

using namespace std;
vector<pair<int,pair<int,int>>> node;
int parent[101];

int find(int i){
    if(parent[i]==i) return i;
    return find(parent[i]);
}

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return a.second.second < b.second.second;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    for(int i=0; i<costs.size(); i++){
        node.push_back({costs[i][0],{costs[i][1],costs[i][2]}});
    }
    sort(node.begin(),node.end(),cmp);
    for(int i=0; i<node.size(); i++){
        int a = find(node[i].first);
        int b = find(node[i].second.first);
        if(a!=b){
            parent[a] = b;
            answer += node[i].second.second;
        }
    }
    
    return answer;
}
