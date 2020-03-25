class Solution {
  public String solution(int n) {
      String answer = "";
      
      while(n>0){
          if(n%3==0){
              answer+= '4';
              n = (n - 1) / 3;
          }else if(n%3==1){
              answer+= '1';
              n = (n - 1) / 3;
          }else{
              answer+='2';
              n = (n - 1) / 3;
          }
      }
      return answer;
  }
}