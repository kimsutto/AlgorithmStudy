class Solution {
    public long solution(int N) {
        long[] arr = new long[N];
        long answer = 0;
        arr[0]=1;
        
        if(N==2){
            arr[1]=1;
            answer = 6;
            return answer;
        }
        
        if(N>2){
            arr[1]=1;
            for(int i=2; i<arr.length; i++){
                arr[i]=arr[i-1]+arr[i-2];
            }
            answer= arr[N-1]*4 + arr[N-2]*2;
            return answer;
        }
     return answer;
    }   
}