#include<bits/stdc++.h>

using namespace std;
//위상 정렬

int main(void) {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v;
  int degree[32001] ={0};
  queue<int> q;

  for(int i=0;i<N;i++){
    v.push_back({});
  }
  for(int i=0; i<M ; i++){
    int a,b;
    cin >> a >> b;
    v[a-1].push_back(b-1);
    degree[b-1]+=1;
  }
 // cout <<v.size();
    for(int i=0; i<N;i++){
      if(degree[i]==0){
        q.push(i);
      }
    }
  

  while(!q.empty()){
      int qq = q.front();
      cout << qq+1 << " ";
      q.pop();

      for (int i = 0; i < v[qq].size(); i++){
         degree[v[qq][i]]--;
         if (degree[v[qq][i]]==0){
            q.push(v[qq][i]);
         }
      }
     
      
  } 
    return 0;
}