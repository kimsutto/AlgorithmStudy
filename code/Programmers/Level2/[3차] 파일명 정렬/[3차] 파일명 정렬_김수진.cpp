#include <bits/stdc++.h>

using namespace std;

struct FileName{
    string head; 
    int number;
    string tail;
    string entr;
};

bool cmp(FileName a, FileName b){
    if(a.head==b.head){
        return a.number < b.number;
    }
    
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<FileName> fn;
    for(string s : files){
        string shead = "";
        string snumber = "";
        string stail = "";
        bool chk = true;
        bool chk2 = true;
        for(char c : s){
            if(chk && isdigit(c)==0){
                shead += toupper(c);
            }else if(chk2 && isdigit(c)!=0){
                chk = false;
                snumber += c;
            }else{
                chk2 = false;
                stail += c;
            }
        }
        fn.push_back({shead,stoi(snumber),stail,s});
        cout << shead << stoi(snumber) << stail <<endl;
    }
    stable_sort(fn.begin(), fn.end(),cmp);
    for(int i=0; i<fn.size(); i++){
        answer.push_back(fn[i].entr);
    }
    return answer;
}
