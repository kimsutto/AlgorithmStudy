#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Point{
    int x, y, d, time;
};

int N, M; 
int g_count, r_count;
int garden[51][51];
int cp_garden[51][51];
int cnum = 0;

vector<pair<int,int>> grow;
int answer = 0; 
vector<pair<int,int>> g_f;
vector<pair<int,int>> r_f;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<Point> q;


int count(){
    int cnt = 0;
    int tt[51][51] = {0,};

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size ; i++){
            
            int x = q.front().x;
            int y = q.front().y;
            int d = q.front().d;
            int time = q.front().time;
            
            q.pop();

            if(cp_garden[x][y]==5)
                continue;
    
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(cp_garden[nx][ny]==0)
                    continue;
                if(nx>=0 && ny>=0 && nx<N && ny<M ){
                    if(cp_garden[nx][ny]==1 || cp_garden[nx][ny]==2 ){
                        cp_garden[nx][ny] = d;
                        q.push({nx,ny,d,time+1});
                        tt[nx][ny]= time;
                    }else{
                        if((tt[nx][ny]==time) && cp_garden[nx][ny]!=d){
                            cnt++;
                            cp_garden[nx][ny] = 5;
                            tt[nx][ny] = -1;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

void farming(){
    vector<int> color(cnum, 0);

    for(int i = 0; i < g_count+r_count; i++){
        if(i < g_count) color[i] = 3;
        else color[i] = 4;
    }

    sort(color.begin(), color.end());
    for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cp_garden[i][j] = garden[i][j];

    do{
        
        for(int i = 0; i < cnum; i++) {
            if(color[i] != 0) {
                int x = grow[i].first;
                int y = grow[i].second;
                cp_garden[x][y] = color[i];
                q.push({x,y,color[i],1});
            }
        }
        answer = max(answer,count());
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                cp_garden[i][j] = garden[i][j];
    }while(next_permutation(color.begin(), color.end()));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    cin >> N >> M >> g_count >> r_count;

    for(int i=0; i<N ; i++){
        for(int j=0; j<M ; j++){
            cin >> garden[i][j];
            if(garden[i][j]==2){
                grow.push_back(make_pair(i,j));
                cnum++;
            }
        }
    }
    farming();
    
    cout << answer;
    return 0;
}
