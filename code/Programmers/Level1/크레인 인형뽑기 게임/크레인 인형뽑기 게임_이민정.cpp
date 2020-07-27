#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> bucket;
    
    for(int i = 0; i < moves.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[j][moves[i]-1] != 0 ){
                if(!bucket.empty()){
                    if(bucket.top() == board[j][moves[i]-1]) {
                        answer += 2;
                        bucket.pop();
                    }
                    else bucket.push(board[j][moves[i]-1]);
                }
                else bucket.push(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}
