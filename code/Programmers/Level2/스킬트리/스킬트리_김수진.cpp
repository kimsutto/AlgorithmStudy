#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    map<char, int> s;
    vector<int> a;
    for(int i=0; i<skill.size();i++){
        s[skill[i]]=i;
        a.push_back(i);
    }
    
    for(int i=0; i<skill_trees.size(); i++){
        vector<int> prior;
        for(int j=0;j<skill_trees[i].size();j++){
            if(s.count(skill_trees[i][j])!=0){
                prior.push_back(s[skill_trees[i][j]]);
            }
        }
        for(int k=0;k<prior.size();k++){
            if(prior[k]!=a[k]){
                answer--;
                break;
            }
        }
    }
    return answer;
}
