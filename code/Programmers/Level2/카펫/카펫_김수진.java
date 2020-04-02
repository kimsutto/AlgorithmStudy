class Solution {
    public int[] solution(int brown, int red) {
        int[] answer = {0,0};
        
        for(int i=1;i<=red;i++){
            int redWidth = red/i;
            int redHeight = i;
            
            int brownNum = (redWidth+2) * (redHeight+2);
            
            if((brownNum-red) <= brown){
                answer[0] = redWidth+2;
                answer[1] = redHeight+2;
                return answer;
            }
        }
        return answer;
    }
}