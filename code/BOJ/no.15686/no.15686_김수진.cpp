#include <iostream>
#include <vector>

using namespace std;

int N, M;
int board[51][51];
vector<pair<int,int>> house;
vector<pair<int,int>> chicken;

int len(pair<int,int>a, pair<int,int>b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

int main(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //input
    cin >> N >> M; 

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> board[i][j];
            if(board[i][j]==1){
                house.push_back({i,j});
            }else if(board[i][j]==2){
                chicken.push_back({i,j});
            }
        }
    }
    int answer = 1e9;
    //조합
    vector<int> com(chicken.size(), 1);
    fill(com.begin(), com.begin()+chicken.size()-M,0);
    do{
        int city_dist = 0;
        for(int i=0; i<house.size(); i++){
            int dist = 1e9;
            for(int j=0; j<chicken.size(); j++){
                if(com[j]==0) continue;
                dist = min(dist,len(house[i],chicken[j]));
            }
            city_dist += dist;
        }
        answer = min(answer, city_dist);
    }while(next_permutation(com.begin(),com.end()));

    cout << answer;

}
