import java.util.PriorityQueue;

class Solution {
   public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueueInteger queue = new PriorityQueueInteger();
        
        for (int i=0; iscoville.length; i++) {
            queue.add(scoville[i]);
        }
        while(queue.peek()  K) {
        	if(queue.size() == 1) return -1;
        	
        	int first = queue.poll();
        	int second = queue.poll();
        	
        	int result = first + (second2);
        	
        	queue.add(result);
        	answer++;
        }
        return answer;
   }
}