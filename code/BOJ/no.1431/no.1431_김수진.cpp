#include<bits/stdc++.h>

using namespace std;

bool compare(string a, string b){
    int suma = 0; 
    int sumb = 0;
    if(a.size() != b.size()){
        return a.size() < b.size(); // 
    } else{
        for(int i=0; i<a.size(); i++){
            if(a[i]-'0' <=9 && a[i] - '0' >=0){
                suma += a[i] - '0';
            }
        }
        for(int i=0; i<a.size(); i++){
            if(b[i]-'0' <=9 && b[i] - '0' >=0){
                sumb += b[i] - '0';
            }
        }
        if(suma != sumb){
            return suma < sumb;
        }
    }
    return a < b; 
}

int main() {    
    vector<string> v; 
    int n;
    cin >> n; 
    
    for(int i=0; i< n; i++){
        string str;
        cin >> str; 
        v.push_back(str);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<n ; i++){
        cout << v[i] << "\n";
    }
    
    return 0;
}
