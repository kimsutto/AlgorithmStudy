#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0, i = 0;
    stack<int> s;

    for (i = 0; i < 5 && board[i][moves[0] - 1] == 0; i++);
    cout << i << endl;
    if (i < board.size()) {
        s.push(board[i][moves[0] - 1]);
        board[i][moves[0] - 1] = 0;
    }

    for (i = 1; i < moves.size(); i++) {
        int j = 0;
        for (; j < board.size() && board[j][moves[i] - 1] == 0; j++);
        if (j < board.size()) {
            if (!s.empty() && s.top() == board[j][moves[i] - 1]) {
                s.pop();
                answer += 2;
            }
            else {
                s.push(board[j][moves[i] - 1]);
            }
            board[j][moves[i] - 1] = 0;
        }

    }

    return answer;
}

int main() {
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1} };
    vector<int> moves = { 1,5,3,5,1,2,1,4 };

    cout << endl << solution(board, moves) << endl;
    return 0;
}