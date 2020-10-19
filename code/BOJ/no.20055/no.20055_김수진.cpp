#include<iostream>

using namespace std;

int N, M;
int moving[203];
bool moving_people[203] = {false,};

int main(){
    freopen("input.txt", "r", stdin);
    cin >> N >> M;
    for(int i = 1; i <= 2*N; i++){
        cin >> moving[i];
    }
    int spend = 0;
    int disable = 0;
    bool chk = true;

    while(true){
        spend++;

        //1.컨테이너 벨트, 로봇 회전
        int final = moving[2*N];
        for(int i=2*N-1; i>=1; i--){
            moving[i+1] = moving[i];
        }
        moving[1] = final;

        for(int i=N-1; i>=1; i--){
            if(moving_people[i]){
                moving_people[i+1] = true;
                moving_people[i] = false;
            }
        }
        moving_people[N] = false;

        //2. 로봇 이동 
        for(int i=N-1; i>=1; i--){
            if(!moving_people[i])
                continue;
            if(moving[i+1]>0&&moving_people[i+1]==false){
                moving_people[i+1] = true;
                moving_people[i] = false;
                moving[i+1]--;
               if(moving[i+1]==0)
                    disable++;
            }
            moving_people[N] = false;
        }
        
        //3. 컨테이너 탑승 
        if(moving[1]>0 && moving_people[1]==false){
            moving_people[1] = true;
            moving[1]--;
            if(moving[1]==0)
                disable++;
        }
        
        if(disable>=M) break;
    }

    cout << spend;

}
