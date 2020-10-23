#include <string>
#include <vector>

using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size(); 
    
    for(int i=0; i<size; i++){
        for(int j=0; j<i+1; j++){
            dp[i][j] = triangle[i][j];
        }
    }
    for(int i=1; i<size; i++){
        for(int j=0; j<size; j++){
            if(j==0)
                dp[i][j] = dp[i-1][j]+dp[i][j];
            else if(j==i)
                dp[i][j] = dp[i-1][j-1]+dp[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + dp[i][j];
        }
    }
    
    for(int i=0; i<size ; i++){
        answer = max(answer,dp[size-1][i]);
    }
    return answer;
}
