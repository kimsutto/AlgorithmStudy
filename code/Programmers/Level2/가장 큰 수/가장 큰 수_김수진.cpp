#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    if(a+b>b+a) return true;
    else return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(auto i : numbers){
        v.push_back(to_string(i));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto i : v){
        answer += i;
    }
    if(answer[0]=='0')
        answer = "0";
    return answer;
}
