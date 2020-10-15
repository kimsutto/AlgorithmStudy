#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;
//N : 땅크기, M :나무 ,K : k년 지난 후
int N,M,K;

int ground[11][11]; //5로 초기화
int robot[11][11];
deque<int> tree[11][11];

int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {-1,-1,-1,0,0,1,1,1};


int answer = 0;

void solve(int year){

    vector<pair<int,pair<int,int>>> dead,sp;
    //spring
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int size = tree[i][j].size();
            while(size>0){
                int age = tree[i][j].front();
                tree[i][j].pop_front();
                if(ground[i][j]>=age){
                    ground[i][j] -=age;
                    tree[i][j].push_back(age+1);
                    if((age+1)%5==0)
                        sp.push_back(make_pair(age,make_pair(i,j)));
                }else{
                    dead.push_back(make_pair(age,make_pair(i,j)));
                }
                size--;
            }
        }
    }

  //summer
  for(auto i : dead){
    int x= i.second.first;
    int y = i.second.second;
    int z = i.first;
    ground[x][y] += z/2;
  }     

  //fall
  for(int i=0; i<sp.size(); i++){
    int x = sp[i].second.first;
    int y = sp[i].second.second;

      for(int j=0; j<8; j++){
        int nx = x+dx[j];
        int ny = y+dy[j];
        if(nx>=0 && ny >=0 && nx<N && ny<N){
          tree[nx][ny].push_front(1);
        }
      }
  }

  //winter
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      ground[i][j] += robot[i][j];
    }
  }


}

int main() {
    freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> robot[i][j];
            ground[i][j] = 5;
        }
    }
    for(int i=0; i<M; i++){
        int x, y, z;
        cin >> x >> y >>z;
        tree[x-1][y-1].push_back(z);
    }
    for(int i=0; i<K; i++){
        solve(i);
    }
    int answer =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            answer += tree[i][j].size();    
        }
    }

    cout << answer;

return 0;
}
