#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());
    
    for(int i=0; i<commands.size(); i++){
        vector<int> cut;
        cut.assign(array.begin()+commands[i][0]-1,array.begin()+commands[i][1]);
        sort(cut.begin(),cut.end());
        answer[i] = cut[commands[i][2]-1];
    }    
    
    return answer;
}
