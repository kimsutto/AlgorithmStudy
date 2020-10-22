#include <bits/stdc++.h>

using namespace std;

int nn;

string solve(int a){
    string b = "";
    while(a){
        if(a%2 == 0)
            b+='0';
        else
            b+='1';
        a /= 2;
    }
    while(b.size()!=nn){
        b+='0';
    }
    reverse(b.begin(), b.end());
    return b;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    nn = n;
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        string s = solve(arr1[i]|arr2[i]);
        string str = "";
        for(int j=0; j<n; j++){
            if(s[j]=='1')
                str+='#';
            else
                str+=' ';
        }
        answer.push_back(str);
    }
    return answer;
}
