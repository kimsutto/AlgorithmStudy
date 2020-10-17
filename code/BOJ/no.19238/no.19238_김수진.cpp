#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std; 

//N 크기, M 태울 수 , fuel(~500,000)
int N,M, fuel;
int board[22][22];
int dist[22][22];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<pair<int,pair<int,int>>> person;
int visited[403];
int complete = 0; 
vector<pair<int,int>> dest[403];
int xx, yy; // 현재 위치 

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) 
{
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second; 
    return a.second.first < b.second.first; 
}

int diff(){
    queue<pair<int,int>> q;
    q.push({xx,yy});
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N;j++){
            dist[i][j] = 99999999;
        }
    }
    dist[xx][yy] = 0;
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx>=1 && ny>=1 && nx<=N && ny<=N && board[nx][ny]!=1){
                if(dist[nx][ny]>dist[xx][yy]+1){
                    dist[nx][ny] = dist[xx][yy] +1;
                    q.push({nx,ny});
                }
            }
        }

    }
    int mx = 100000000; 
    int mi = 0;
    for(int i=0; i<person.size(); i++){
        if(visited[i])
            continue;
        
        if(mx>dist[person[i].second.first][person[i].second.second]){
            mx = dist[person[i].second.first][person[i].second.second];
            mi = i;

        }
    }
    visited[mi] = true;
    xx = person[mi].second.first;
    yy = person[mi].second.second;
    fuel -= mx;
    return person[mi].first;
}
int move(int i){
    queue<pair<int,int>> q;
    q.push({xx,yy});
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N;j++){
            dist[i][j] = 99999999;
        }
    }
    dist[xx][yy] = 0;

    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx>=1 && ny>=1 && nx<=N && ny<=N && board[nx][ny]!=1){
                if(dist[nx][ny]>dist[xx][yy]+1){
                    dist[nx][ny] = dist[xx][yy] +1;
                    q.push({nx,ny});
                }
            }
        }
    }
    xx = dest[i][0].first;
    yy = dest[i][0].second;
    complete++;
    return dist[xx][yy];
}

void solve(){
    while(complete<M){
        int i = diff();
        if(fuel<0){
            fuel = -1;
            return;
        }else{
            int d = move(i);
            fuel -= d;
            if(fuel<0){
                fuel = -1;
                return;
            }else{
                fuel += d*2;
            }
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> N >> M >> fuel;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> board[i][j];
        }
    }
    cin >> xx >> yy;
    for(int i=0; i<M; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        person.push_back({i,{a,b}});
        dest[i].push_back({c,d});
    }
    sort(person.begin(), person.end(), cmp);
    solve();
    cout << fuel;
}
