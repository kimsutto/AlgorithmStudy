class Solution {
  public long solution(long n) {
      long answer = 0;
      long temp =(long)Math.sqrt(n);
      if(temp*temp==n)
          answer=(temp+1)*(temp+1);
      else
          answer=-1;
      return answer;
  }
}