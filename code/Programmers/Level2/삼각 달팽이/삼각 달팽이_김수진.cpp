#include <string>
#include <vector>

using namespace std;
int tri[1001][1001] = {0,};
vector<int> solution(int n) {
    vector<int> answer;
    int x = 1, y= 0;
    int nn = 1;
    int num = 1; 
    for(int i=0; i<=n; i++){
        if(num==1){ //위-> 아래
            for(int j=i; j<n; j++){
                tri[x++][y] = nn++;
            }
            x--; 
            y++;
            num = 2;
        }else if(num==2){ //왼 -> 오
            for(int j=i; j<n; j++){
                tri[x][y++] = nn++;
            }
            x--;
            y--;
            y--;
            num = 3;
        }else{ //아래 -> 위 
            for(int j=i; j<n; j++){
                tri[x--][y--] = nn++;
            }
            x++; x++; y++;
            num = 1;
        }
        
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            answer.push_back(tri[i][j]);
        }
    }
    
    return answer;
}
