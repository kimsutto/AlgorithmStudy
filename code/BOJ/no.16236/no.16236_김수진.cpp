#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Fish{
    int siz, x, y;
};

int N; 
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int board[21][21];
int dist[21][21];
int x, y;
int sharksize = 2;
vector<Fish> fish;
int visited[404];
int tim = 0;
bool chk = true;
int cnt = 0;

bool cmp(Fish a, Fish b){
    if(a.x==b.x)
        return a.y < b.y;
    return a.x < b.x;
}

void move(){
    queue<pair<int,int>> q;
    q.push({x,y});
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dist[i][j] = 1e9; 
        }
    }
    dist[x][y]=0; 
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<N&&board[nx][ny]<=sharksize){
                if(dist[nx][ny] > dist[xx][yy]+1){
                    dist[nx][ny] = dist[xx][yy]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int mx = 1e9;
    int mi = 0;
    for(int i=0; i<fish.size(); i++){
        if(visited[i]) continue;
        if(fish[i].siz>= sharksize) continue;
        if(mx>dist[fish[i].x][fish[i].y]){
            mx = dist[fish[i].x][fish[i].y];
            mi = i;
        }    
    }
    if(mx == 1e9){
        chk = false;
        return;
    }
    x = fish[mi].x;
    y = fish[mi].y;
    visited[mi] = true;
    int spend = dist[x][y];
    tim += spend;
    cnt++;
    if(cnt==sharksize){
        sharksize++;
        cnt = 0;
    }
}

void solve(){
    while(chk){
        move();
    }
}


int main(){
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j]>0){
                if(board[i][j]==9){
                    board[i][j] = 0;
                    x = i; y= j;
                }
                else{
                    fish.push_back({board[i][j],i,j});
                }
            }
        }
    }

    if(fish.size()==0){
        cout << 0;
        return 0;
    }
    sort(fish.begin(),fish.end(),cmp);
    
    solve();
    cout << tim;

}
