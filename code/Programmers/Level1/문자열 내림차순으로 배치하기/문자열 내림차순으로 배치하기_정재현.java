import java.util.*;
class Solution {
  public String solution(String s) {
      String answer = "";
      char[] temp = s.toCharArray();
      int[] intTemp = new int[temp.length];
      for(int i=0; i<temp.length; i++){
          intTemp[i]=(int)temp[i];
      }
      Arrays.sort(intTemp);
      for(int i=0; i<intTemp.length; i++){
          temp[intTemp.length-1-i]=(char)intTemp[i];
      }
      answer=new String(temp);          
      return answer;
  }
}