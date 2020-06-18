#include <bits/stdc++.h>
using namespace std;
bool check[200001];
vector<int> adj[200001];

int dfs(int a){
	if(check[a]) return 0;
	int num = 1;
	check[a] =1;
	for(int i =0; i<adj[a].size(); i++){
		int next = adj[a][i];
		num += dfs(next);
	}
	return num;
}
int main() {
	int N, M; 
	cin >> N >> M;
	
	for(int i=0; i<M; i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int answer1=0;
	int answer = 0;
	
	for(int i=1;i<=N;i++){
		int answer2 = dfs(i);
		
		if(answer2 == N){
			cout << i << " "<< answer2;
			return 0;
		}
		if(answer2 > answer1){
			answer1 = answer2;
			answer = i;
		}
	}
	cout << answer <<" "<< answer1;
	return 0;
}
