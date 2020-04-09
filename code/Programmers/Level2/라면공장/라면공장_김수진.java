import java.util.*;

class Solution {
    public int solution(int stock, int[] dates, int[] supplies, int k) {
        int answer = 0;
        int i = 0;
        
        //왜 직접Compare 오버라이드해서 하는게 안되는지 모르겠음.. 일단 이걸로 함 
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        
     
        for(int j=0; j<k;j++){
            if(j==dates[i]){
                pq.add(supplies[i]);
                if(i+1<dates.length){
                    i++;
                }
                
            }
            if(stock==0){
                stock += pq.poll();
                answer++;
            }
            stock -= 1;
        }
        
        return answer;
    }
}