#include <bits/stdc++.h>

using namespace std;
int N;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a , pair<int,int> b){
    return a.first < b.first;
}

int main(){
    //freopen("input.txt", "r", stdin);
    int answer = 0;
    int mx = 0;
    int mxx = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b; 
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<v.size(); i++){
        if(mx<v[i].second){
            mx = v[i].second;
            mxx = i;
        }
    }

    int startH = v[0].second; 
    int current = v[0].first;
    int cnt = 0;

    //시작 -> 젤 높은 곳
    for(int i=1; i<=mxx; i++){
        if(v[i].second>startH){
            answer += (v[i].first - current)*startH;
            current = v[i].first;
            startH = v[i].second;
        }else cnt++;
    }
    
    //젤 높은 곳 
    answer += startH;


    startH = v[v.size()-1].second; 
    current = v[v.size()-1].first;
    

    //젤 높은 곳 -> 끝
    for(int i=v.size()-2; i>mxx ; i--){
        if(v[i].second>startH){
            answer += (current - v[i].first)*startH;
            current = v[i].first;
            startH = v[i].second;
        }else cnt++;
    }
    answer += (current-v[mxx].first)*startH;

    cout << answer;
}
