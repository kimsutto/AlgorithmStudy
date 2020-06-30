#include<bits/stdc++.h>

using namespace std;

longlong dp[101][10];

int main(){
  long long answer = 0;
  int n;
  cin >> n; 
  for(int i=1; i<=n; i++){
    for(int j=0; j<10; j++){
      if(i==1)
        dp[i][j] = 1; 
      else{
        if(j>0)
          dp[i][j] += dp[i-1][j-1];
        if(j<9)
          dp[i][j] += dp[i-1][j+1];
        dp[i][j] %= 1000000000;
      }
    }
  }
  for(int i=0; i<10; i++){
    answer += dp[n][i];
    answer %= 1000000000;
  }
  cout << answer;
}
