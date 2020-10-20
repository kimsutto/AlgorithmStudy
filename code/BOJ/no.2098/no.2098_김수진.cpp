#include <iostream>

using namespace std;

int N;
int node[17][17];
int dp[17][1<<16]; //메모제이션 용


int tsp(int current, int visited){
    if(visited == (1<<N)-1 && node[current][0]!=0)
        return node[current][0];

    int &re = dp[current][visited];
    
    if(re !=0)
        return re;
    else
        re = 1e7;
    
    for(int i=0; i<N; i++){
        if(node[current][i]!=0 && (visited & (1<<i)) ==0)
            re = min(re, node[current][i]+tsp(i,visited | (1<<i)));
    }
    return re;        
}


int main(){
    freopen("input.txt", "r", stdin);
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> node[i][j];
        }
    }

    cout << tsp(0,1);
    return 0;
}
