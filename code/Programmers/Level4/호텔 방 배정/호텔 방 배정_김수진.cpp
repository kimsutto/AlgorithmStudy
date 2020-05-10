#include<bits/stdc++.h>


using namespace std;
map<long,long> m;
vector<long long> answer;


long long next(int n){
    if(m.count(n)==0){
        return n;
    }else{
        m[n] = next(m[n]);
    }
    return m[n];
}
vector<long long> solution(long long k, vector<long long> room_number) {
    
    for(int i=0; i<room_number.size(); i++){
        int j = room_number[i];
        
        if(m.count(j)==0){
            answer.push_back(j);
            long long k = j+1;
            long long nex = next(k);
            m[j]=nex;
            
        }else{
            long long ne = next(j);
            answer.push_back(ne);
            long long kk = m[j];
            long long nex= next(kk+1);
            m[ne]=nex;
        }
    }    
    return answer;
}