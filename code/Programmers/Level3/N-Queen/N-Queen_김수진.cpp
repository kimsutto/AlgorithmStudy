#include <string>
#include <vector>

using namespace std;

int answer = 0;



void backtracking(int col[],int column, int n){
       if(column==n+1){
           answer++;
           return;
        }else{
           for(int j=0; j<n; j++){
              bool confirm = true;
               for (int i = 1; i < column; i++) {
				if (col[i] == j  || j == col[i]+(column-i) || j== col[i]-(column-i)) {	
					confirm = false;
					break;
				}
			}
                   
               if(confirm){
                   col[column] = j;
                   backtracking(col,column+1,n);
               }
           }
       }
}

int solution(int n) {
    int col[13] ={0};
    backtracking(col,1, n);
    
    return answer;
}