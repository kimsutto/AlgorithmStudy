#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> ans;
    
    for(int i=0; i<strings.size(); i++){
        ans.push_back(make_pair(strings[i][n], strings[i]));
    }
    sort(ans.begin(), ans.end());
    
    for(int i=0; i<ans.size(); i++){
        answer.push_back(ans[i].second);
    }
    
    return answer;
}
