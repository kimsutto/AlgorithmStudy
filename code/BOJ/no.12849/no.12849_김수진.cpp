#include<iostream>

using namespace std;

int D;

int main(){
    cin >> D;
    //0초의 정보,전산,미래,신양,환경,진리,학생,형남
    long long dp[8] = {1,0,0,0,0,0,0,0};
    
    while(D>0){
        long long tmp[8] = {0,0,0,0,0,0,0,0};
        tmp[0] = dp[1]+dp[2];
        tmp[1] = dp[0]+dp[2]+dp[3];
        tmp[2] = dp[0]+dp[1]+dp[3]+dp[4];
        tmp[3] = dp[1]+dp[2]+dp[4]+dp[5];
        tmp[4] = dp[2]+dp[3]+dp[5]+dp[7];
        tmp[5] = dp[3]+dp[4]+dp[6];
        tmp[6] = dp[5]+dp[7];
        tmp[7] = dp[4]+dp[6];

        for(int i=0; i<8; i++){
            dp[i] = tmp[i]%1000000007;
        }
        D-=1;
    }
    cout <<dp[0] <<endl;
}
