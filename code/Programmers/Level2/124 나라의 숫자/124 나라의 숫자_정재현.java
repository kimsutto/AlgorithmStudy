class Solution {
    public String solution(int n) {
        String answer = "";
        String[] numbers = {"4", "1", "2"};
        int num = n;
        
        while(num>0){
            int remainder = num % 3;
            num/=3;
            
            if(remainder==0) num--;
            
            answer=numbers[remainder]+answer;
        }
        
        return answer;
    }
}