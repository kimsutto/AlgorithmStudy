#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size() ; i++){
        int a = prices[i];
        int j= i+1;
        for( ; j<prices.size(); j++){
            if(a>prices[j]){
                answer.push_back(j-i);
                break;
            }
        }
        if(j>=prices.size()){
            answer.push_back(j-i-1);    
        }   
    }
    return answer;
}