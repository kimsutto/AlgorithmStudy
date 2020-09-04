#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n){
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    int min = 1; 
    int max = distance; 
    int mid = 0;
    
        while(min <= max){
            int cnt = 0;
            int m = 0;
            mid = (min + max) / 2;
            
            for(int i = 0 ; i < rocks.size() ; i++){
                if(rocks[i] - m < mid){
                    cnt++;
                } else {
                    m = rocks[i];
                }
            }
            if(distance - m < mid) cnt++;
            //mid 조정 
            if(cnt <= n){
                if(mid > answer)
                    answer = mid;
                min = mid +1;    
            } else {
                max = mid - 1;
            }
        }
    return answer;
}
