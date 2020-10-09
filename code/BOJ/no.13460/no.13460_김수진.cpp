#include <vector>
#include <iostream>

using namespace std;

char board[11][11];
int answer = 100000;
int rx, ry;
int bx, by;
bool visited[11][11][11][11] = { false, };
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int N; 
int M;

void solve(int idx, int rx, int ry, int bx, int by){

    if(idx>=10) return;

    
    for(int i=0; i<4; i++){
        int mrx = rx;
        int mry = ry;

        int mbx = bx;
        int mby = by;

        while(board[mrx][mry]!='O' && board[mrx+dx[i]][mry+dy[i]]!='#'){
            mrx+=dx[i];
            mry+=dy[i];
            
            
        }
        
        while(board[mbx][mby]!='O' && board[mbx+dx[i]][mby+dy[i]]!='#'){
            mbx+= dx[i];
            mby+= dy[i];
        }
        
        if(board[mbx][mby]=='O') continue;
        if(board[mrx][mry]=='O') {
            answer = min(answer,idx);
            return; 
        }
        
        if (mrx == mbx && mry == mby) {
            if (abs(mrx - rx) + abs(mry - ry) < abs(mbx - bx) + abs(mby - by)){
                mby -= dy[i];
                mbx -= dx[i];
            }
            else {
                mry -= dy[i];
                mrx -= dx[i];
            }
        }



        if(visited[mrx][mry][mbx][mby]) continue;
        visited[mrx][mry][mbx][mby] = true;
        solve(idx+1, mrx,mry,mbx,mby);
        visited[mrx][mry][mbx][mby] = false;
    }
}






int main(){
    freopen("input.txt", "r", stdin);
    

    cin >> N;
    cin >> M; 
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j]=='R')
                rx = i, ry = j;
            else if(board[i][j]=='B')
                bx = i, by = j;
        }
    }
    visited[rx][ry][bx][by] = true;
    solve(1,rx,ry,bx,by);
    if(answer>9) answer = -1;
    cout << answer;

    return 0;
}
