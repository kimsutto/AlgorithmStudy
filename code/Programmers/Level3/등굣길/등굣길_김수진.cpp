#include <string>
#include <vector>

using namespace std;

int board[101][101];
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0; i<puddles.size(); i++){
        board[puddles[i][0]][puddles[i][1]] = 1;
    }
    dp[0][1] = 1;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]==1)
                dp[i][j] = 0;
            else
                //오른쪽이나 아래로만 갈수있음
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
        }
    }
    return dp[m][n];
}
