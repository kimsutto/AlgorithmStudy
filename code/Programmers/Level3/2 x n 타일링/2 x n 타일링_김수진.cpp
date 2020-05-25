#include <string>
#include <vector>

using namespace std;

// 삽질했는데 dp인 문제들 화가난다 화가난다 
int solution(int n) {
    int answer = 0;
    int dp[n+1];
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= n; i++) {
		dp[i] = (dp[i-1] + dp[i-2])%1000000007;
	}
	answer = dp[n];
    
    return answer;
}
