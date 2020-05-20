 #include <bits/stdc++.h>

using namespace std;

int answer = 51;
int checked[51] = {0};

int differ(string a, string b){
    int size = a.size();
    int num = 0;
    for(int i=0; i<size; i++){
        if(a[i]!=b[i]){
            num++;
        }
    }
    return num;
}

void dfs(string a, string b, int n, vector<string> w){
    if(a==b){
        answer = min(answer,n);
        return;
    }
    for(int i = 0; i<w.size(); i++){
        if(differ(w[i],a)==1&&checked[i]==0){
            checked[i]=1;
            dfs(w[i],b,n+1,w);
            checked[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    for(int i = 0; i<words.size(); i++){
        if(differ(words[i],begin)==1){
            checked[i]=1;
            dfs(words[i],target,1,words);
            checked[i]=0;
        }
    }
    if(answer==51){
        answer = 0;
    }
    return answer;
}
