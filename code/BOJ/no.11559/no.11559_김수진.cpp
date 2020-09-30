#include <bits/stdc++.h>


using namespace std;

char puyo[12][6];
int answer = 0;
//상,하,우,좌
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[12][6];
bool flag = false;
int cnt = 0;
vector<pair<int, int>> temp, temp2;

void dfs(int i, int j){  
    

    for(int k=0; k<4; k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        
        if(0<=nx && nx <12 && 0<=ny && ny<6){
            if(puyo[nx][ny]==puyo[i][j]&&visited[nx][ny]==false){
                cnt++;
                visited[nx][ny]=true;
                temp.push_back(make_pair(nx,ny));
                dfs(nx,ny);
            }
        }
    }
    

}


int main() {
    //input 
    
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin >> puyo[i][j];
        }
    }



    while(1){
        memset(visited, false, sizeof(visited));
        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                cnt =1;
                if(puyo[i][j]!='.' && !visited[i][j]==false){
                    temp.push_back(make_pair(i,j));
                    visited[i][j]= true;
                    
                    dfs(i,j);

                    if(cnt >=4){
                        flag = true;
                        for(int k=0; k<temp.size(); k++){
                            int x = temp[k].first;
                            int y = temp[k].second;
                            puyo[x][y] = '.';
                        }
                    }
                    temp.clear();
                    
                }
            }
        }
        
        //중력
        for(int i=0; i<6; i++){
            int ht = 0;
            for(int j = 11; j>=0; j--){
                if(puyo[j][i]=='.'){
                    ht++;
                }else{
                    puyo[ht+j][i] = puyo[j][i];
                    if(ht+j != j)
                        puyo[j][i] = '.';
                }
            }
        }
        

        if(flag==false){
            break;
        }
        answer++;
    }

    cout << answer;

    return 0;
}
