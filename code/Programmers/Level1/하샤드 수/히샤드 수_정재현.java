import java.util.*;
class Solution {
  public boolean solution(int x) {
      boolean answer = true;
      
      String a=""+x;
      String[] b = a.split("");
      int[] c = new int[b.length];
      
      for(int i=0; i<b.length; i++){
          c[i]=Integer.parseInt(b[i]);
      }
      
      if(x%Arrays.stream(c).sum()==0){
          answer=true;
      }
      else answer=false;
      return answer;
  }
}