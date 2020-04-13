class Solution {
  public String solution(String s) {
      String answer = "";
      String[] temp = s.split("");
      int cnt = 0;
      
      for(String ss : temp)
      {
          if(ss.contains(" "))
              cnt = 0;
          else cnt++;
          
          if(cnt%2==1)
              answer += ss.toUpperCase();
          else if(cnt%2==0)
              answer += ss.toLowerCase();
      }
      
      return answer;
  }
}