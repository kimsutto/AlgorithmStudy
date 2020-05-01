class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for(int i=1; i<=n/2; i++){
            answer += n%i==0 ? i:0;
        }
        answer+=n;
        
        return answer;
    }
}