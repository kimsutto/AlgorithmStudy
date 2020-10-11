#include<iostream>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

int R, C;
char board[101][101];
int visited[101][101]={0,};

int stick_cnt;
int stick[101];
int left = 1;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

//dfs 버전 찾아보기 

void down(){
    vector<pair<int,int>> cluster;
    //find cluster
    queue<pair<int,int>> q;
    for(int i = 0; i<C; i++){
        if(board[R-1][i]=='.'||visited[R-1][i])
            continue;

        q.push(make_pair(R-1,i));
        visited[R-1][i] = 1;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx>=0&&ny>=0&&nx<R&&ny<C){
                    if(board[nx][ny]=='x' && !visited[nx][ny]){
                        visited[nx][ny] = 1;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    //분리된 클러스터들 . 표시하고 cluster벡터에 넣기 
    for(int i = 0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j]&& board[i][j]=='x'){
                cluster.push_back(make_pair(i,j));
                board[i][j] = '.';
            }
        }
    }

   
    //클러스터 비면 리턴 
    if(cluster.size()==0)
        return;
 
    //클러스터 벡터 이동 (아래로만 가능 )
    bool check = true;
    while(check){
        
        for(auto i : cluster){
            int xx = i.first;
            xx++;
            int yy = i.second;
            if(xx >=R || board[xx][yy]=='x'){
                check = false;
                break;
            }
        }

        if(check){
            for(int i=0; i< cluster.size(); i++){
                cluster[i].first++;
            }
        }
    }

    for(auto i : cluster){
        int xx = i.first;
        int yy = i.second;
        board[i.first][i.second] = 'x';
    }
    
}

void thro(int height, int dir){
    if(dir == 1){
        //왼 -> 오
        for(int i=0; i<C; i++){
            if(board[height][i]=='x'){
                board[height][i] = '.';
                break;
            }
        }
    }
    if(dir==0){
        //오 -> 왼
        for(int i=C-1; i>=0; i--){
            if(board[height][i]=='x'){
                board[height][i] = '.';
                break;
            }
        }
    }

}

int main(){
    
    freopen("input.txt", "r", stdin);

    cin >> R >> C; 

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    cin >> stick_cnt;

    for(int i=0; i< stick_cnt ; i++){
        cin >> stick[i];
    }

    for(int i=0; i< stick_cnt ; i++){
        if(i%2 == 0)
            thro(R-stick[i], 1);
        else
            thro(R-stick[i], 0);
        
        down();
        memset(visited, 0, sizeof(visited));
        
    }
 

    //output
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j];
        }
        if(i!=R-1)
            cout <<endl;
        
    }

}
