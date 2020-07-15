#include<bits/stdc++.h>


using namespace std;


vector<int> solution(vector<string> gems) {
    set<string> sss;
    vector<int> answer;
    int result[2];
    for(string i : gems){
        sss.insert(i);
    }
    int size = sss.size();
    int n = gems.size();

    map<string, int> gem;
    int answer1 = 100000;   
    int answer2;
    int f = 0;
    int s = 0;
    gem.insert(make_pair(gems[f],1));

    while(s<n&&f<n){
        if(gem.size()==size){
            answer2 = s-f+1; 
            if(answer2<answer1){
                result[0] = f+1;
                result[1]= s+1;
                answer1 = answer2;
            }
        
            gem[gems[f]] -=1;
        
            if(gem[gems[f]]==0){
                gem.erase(gems[f]);
            }
            f++;
        
        }else{
            if(s<n-1){
                s++;
                if(gem.count(gems[s])==0){
                    gem.insert(make_pair(gems[s],1));  
                }else{
                    gem[gems[s]]+=1;
                }
            }else{
                break;
            }
        }
    }

    answer.push_back(result[0]);
    answer.push_back(result[1]);

    return answer;
}
