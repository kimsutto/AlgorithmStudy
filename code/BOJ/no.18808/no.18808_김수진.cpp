#include <iostream>
#include <vector>

using namespace std;


int N,M,K;
int r,c;
int notebook[41][41]={0,};
int sticker[11][11];

void rotate(){
    int tmp[11][11];

    for(int i=0; i<r;i++){
        for(int j=0; j<c; j++){
            tmp[i][j] = sticker[i][j];
        }
    }
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            sticker[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r,c);
}
bool check(int ii, int jj){
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            if(notebook[ii+x][jj+y]==1 && sticker[x][y]==1){
                return false;
            }
        }
    }

    for(int i=0; i<r ; i++){
        for(int j=0; j<c; j++){
            if(sticker[i][j]==1){
                notebook[ii+i][jj+j]=1;
            }
        }
    }
    return true;
}


int main(){
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> M >> K;

    for(int i=0; i<K; i++){
        cin >> r >> c;
        for(int j=0; j<r ; j++){
            for(int k=0; k<c; k++){
                cin >> sticker[j][k];
            }
        }
       bool complete = false;
        for(int nn = 0; nn<4; nn++){
            bool chk = false;
            for(int ii = 0; ii<=N-r; ii++){
                if(chk)
                    break;
                for(int jj=0; jj<=M-c; jj++){
                    if(check(ii,jj)){
                        complete = true;
                        chk = true;
                        break;
                    }
                }
            }
            if(complete)
                break;
            else
                rotate();
                
        }

    }


    int answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(notebook[i][j]==1)
                answer++;
        }
    }
    cout << answer;
}
