import java.util.*;
class Solution {
  public int[] solution(int[] arr, int divisor) {
      int[] answer = {};
      ArrayList<Integer> temp = new ArrayList<Integer>();
      for(int i=0; i<arr.length; i++){
          if(arr[i]%divisor==0)
              temp.add(arr[i]);
      }
      if(temp.size()==0){
          answer=new int[1];
          answer[0]=-1;
      }
      else{
          answer=new int[temp.size()];
          for(int i = 0; i<temp.size(); i++){
              answer[i]=temp.get(i);
          }
          Arrays.sort(answer);
      }
          
      return answer;
  }
}