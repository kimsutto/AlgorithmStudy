#include<bits/stdc++.h>

using namespace std;

int c[101];
vector<int> a[101];
int result[101] = {0,};


int bfs(int start, int end){
  queue<int> q;
  q.push(start);
  c[start] = true;
  while(!q.empty()){
    int j = q.front();
    q.pop();
    if(j==end){
	return result[end];
    }
    for(int i=0; i< a[j].size(); i++){
      int k = a[j][i];
      if(!result[k]){
        q.push(k);
        result[k] = result[j] +1 ;
      }
    }
  }
  return -1;
}

int main() {
  //노드 갯수 
  int n; 
  cin >> n; 
  int first, second; 
  cin >> first >> second;
  int m;
  cin >> m; 
  for (int i=0; i<m ; i++){
    int x, y; 
    cin >> x >> y; 
    a[x].push_back(y);
    a[y].push_back(x);
  }
  
  cout << bfs(first,second);
  
  return 0;
}
