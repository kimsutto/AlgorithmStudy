class Solution {
  public String solution(int num) {
      String answer = "";
      int chk = num%2;
      if(chk == 0){
          answer = "Even";
      }
      else if(chk == 1)
      {
          answer = "Odd";
      }
      return answer;
  }
}