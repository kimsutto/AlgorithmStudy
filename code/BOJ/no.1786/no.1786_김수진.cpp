#include <iostream>
#include <string>
#include <vector>

using namespace std;

int pi[1000001];


vector<int> kmp(string s, string p){
    vector<int> v; 
    int n = s.size(); 
    int m = p.size(); 
    int j = 0; 
    for(int i = 0; i<n; i++){
        while(j>0 && s[i]!=p[j])
            j = pi[j-1];
        if(s[i]==p[j]){
            if(j==m-1){
                v.push_back(i-m+1);
                j=pi[j];
            }else{
                j++;
            }
        }
    }
    return v;
}

int main(){
    string s, p; 
    getline(cin, s);
    getline(cin, p);

    int m = p.size();
    int j = 0; 
    for(int i=1; i<m; i++){
        while(j>0 && p[i]!=p[j])
            j = pi[j-1];
        if(p[i]==p[j])
            pi[i] = ++j;
    }

    //s에서 p가 나오는 횟수 
    vector<int> mm= kmp(s,p);
    cout << mm.size() << '\n';

    //s에서 p가 나오는 우치 
    for(auto i : mm){
        cout << i+1 << ' ';
    }
    return 0;
}
