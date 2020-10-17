#include <iostream>
#include <vector>

using namespace std;

int N; 
int t,x,y;

int red[4][4];
int green[6][4];
int blue[4][6];
int score; 

void bomb_green(){
    vector<int> x;
    for(int i = 5; i>1; i--){
        bool comp = true;
        for(int j=0; j<4; j++){
            if(green[i][j]==0){
                comp = false;
                break;
            }
        }
        if(comp){
            x.push_back(i);
        }
    }
    if(x.size()==0)
        return;

    for(int ii=0; ii<x.size(); ii++){
        int ix= x[ii];
        score++;
        for(int i=0; i<4; i++){
            green[ix][i] = 0;
        }
    }

    
    for(int i=4; i>=0 ;i--){
        for(int j=0; j<4; j++){
            int dx = 0; 
            if(green[i][j]==2){
                for(int x = i+1; x<6; x++){
                    if(green[x][j]>0 || green[x][j+1]>0){
                        dx=x; 
                        break;
                    }
                }
                if(dx == 0){
                    green[5][j] = 2;
                    green[5][j+1] = 2;
                    green[i][j] = 0; 
                    green[i][j+1]=0;
                    j++;
                    continue;
                }
                if(dx-1 == i){
                    j++;
                    continue;
                }
                green[dx-1][j] =2;
                green[dx-1][j+1] = 2; 
                green[i][j] = 0;
                green[i][j+1] = 0;
                j++;
                continue;
            }
            for(int x = i+1; x<6; x++){
                if(green[x][j]>0){
                    dx=x; 
                    break;
                }
            }
            if (dx == 0) { 
                green[5][j] = green[i][j]; 
                green[i][j] = 0; 
                continue; 
            } 
            if (dx - 1 == i) { 
                continue; 
            } 
            green[dx - 1][j] = green[i][j]; 
            green[i][j] = 0; 
        }
    }
    bomb_green();
}

void bomb_blue(){
    vector<int> x;
    for(int i = 5; i>1; i--){
        bool comp = true;
        for(int j=0; j<4; j++){
            if(blue[j][i]==0){
                comp = false;
                break;
            }
        }
        if(comp){
            x.push_back(i);
        }
    }
    if(x.size()==0)
        return;

    for(int ii=0; ii<x.size(); ii++){
        int ix= x[ii];
        score++;
        for(int i=0; i<4; i++){
            blue[i][ix] = 0;
        }
    }
    
    bomb_blue();
}

int find_green(){
    for(int i=0; i<2;i++){
        for(int j=0; j<4; j++){
            if(green[i][j]>0){
                if(i==0)
                    return 0;
                else
                    return 1;   
            }
        }
    }
    return 3;
}

int find_blue(){
    for(int i=0; i<2;i++){
        for(int j=0; j<4; j++){
            if(blue[j][i]>0){
                if(i==0)
                    return 0;
                else
                    return 1;   
            }
        }
    }
    return 2;
}

void down_green(int t, int y){
    if(t==1){
        int x = 0; 
        while(x+1<6 && green[x+1][y]==0){
            x++;
        }
        green[x][y]=1;
    }else if(t==2){
        int x = 0;
        while(x+1<6 && green[x+1][y]==0 && green[x+1][y+1]==0){
            x++;
        }
        green[x][y]=2;
        green[x][y+1]=2;
    }else{
        int x = 0;
        while(x+1<6 && green[x+1][y]==0){
            x++;
        }
        green[x][y]=3;
        green[x-1][y]=3;
    }
    
    bomb_green();

    int fg = find_green();
    if(fg==0){
        //두칸 내려~~
        for(int i=3; i>=0; i--){
            for(int j=0; j<4; j++){
                green[i+2][j] = green[i][j];
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<4; j++){
                green[i][j] = 0;
            }
        }
    }else if(fg==1){
        //1칸 내려~~
        for(int i=4; i>=1; i--){
            for(int j=0; j<4; j++){
                green[i+1][j] = green[i][j];
            }
        }
        for(int i=1; i<2; i++){
            for(int j=0; j<4; j++){
                green[i][j] = 0;
            }
        }
    }else{

    }
}

void down_blue(int t, int x){
    if(t==1){
        int y = 0; 
        while(y+1<6 && blue[x][y+1]==0){
            y++;
        }
        blue[x][y]=1;
    }else if(t==2){
        int y = 0;
        while(y+1<6 && blue[x][y+1]==0){
            y++;
        }
        blue[x][y]=2;
        blue[x][y-1]=2;
    }else{
        int y = 0;
        while(y+1<6 && blue[x][y+1]==0 && blue[x+1][y+1]==0){
            y++;
        }
        blue[x][y]=3;
        blue[x+1][y]=3;
    }
    
    bomb_blue();

    int fg = find_blue();
    if(fg==0){
        //두칸 내려~~
        
        for(int i=3; i>=0; i--){
            for(int j=0; j<4; j++){
              blue[j][i+2] = blue[j][i];
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<4; j++){
                blue[j][i] = 0;
            }
        }
    }else if(fg==1){
        //1칸 내려~~
        for(int i=4; i>=1; i--){
            for(int j=0; j<4; j++){
                blue[j][i+1] = blue[j][i];
            }
        }
        for(int i=1; i<2; i++){
            for(int j=0; j<4; j++){
                blue[j][i] = 0;
            }
        }
    }else{

    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    cin >> N;
    //t : 1은 1 x 1 (x,y), 2는 1x2 (x,y), (x,y+1) , 3은 2x1 (x,y),(x+1,y)
    for(int i=0; i<N; i++){
        cin >> t >> x >> y; 
        if(t==1){
            down_green(1,y);
            down_blue(1,x);
        }else if(t==2){
            down_green(2,y);
            down_blue(2,x);
        }else{
            down_green(3,y);
            down_blue(3,x);
        }
    }
    cout << score << '\n';
    int cnt = 0;
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            if(green[i][j]>0)
                cnt++;
        }
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            if(blue[i][j]>0)
                cnt++;
        }
    }
    cout << cnt;
}
