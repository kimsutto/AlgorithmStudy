#include<bits/stdc++.h>

using namespace std;

int solution(int n, int m){
	//mCn
	int dp[30][30] = {0};

  for (int i = 0; i <= m; i++){
    dp[i][1] = i;
    dp[i][i] = 1;
    dp[i][0] = 1;
  } 
	
  for(int i=2; i<=m; i++){
    for(int j=2; j<=n; j++){
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }
  }

	return dp[m][n];
}

int main(){

  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int t;
  cin >> t; 

  for(int i=0; i<t; i++){
  	int n,m; 
  	cin >> n >> m; 
  	int nn = solution(n,m);
  	cout << nn <<endl;
  }

  return 0;

} 