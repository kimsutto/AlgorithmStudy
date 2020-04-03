import java.util.*;

class Solution {
    public int solution(int[] weight) {
        Arrays.sort(weight);
        
        int answer = weight[0]; //answer = 1
        
        for(int i=1;i<weight.length; i++){
            if(answer+1<weight[i]){
                return answer+1;
            }
            answer+=weight[i];
        }
        return answer+1;
    }
}