#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int board[26][26];
vector<pair<int,int>> house;
bool visited[26][26] = {false,};
vector<int> answer;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void solve(){
    for(int i=0; i<house.size(); i++){
        if(visited[house[i].first][house[i].second]){
            continue;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(house[i].first,house[i].second));
        visited[house[i].first][house[i].second] = true;
        int len = 0;
        while(!q.empty()){
            len++;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx>=0 && ny>=0 && nx<N && ny<N){
                    if(!visited[nx][ny] && board[nx][ny]==1){
                        visited[nx][ny] = true;
                        q.push(make_pair(nx,ny));
                    }
                }

            }
        }
        answer.push_back(len);
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &board[i][j]);
            if(board[i][j]==1){
                house.push_back(make_pair(i,j));
            }
        }
    }

    solve();

    if(answer.size()==0) {
        cout << 0;
        return 0;
    }
    cout << answer.size() <<endl;
    sort(answer.begin(),answer.end());
    for(int i : answer)
        cout << i <<endl;


    return 0;
}
