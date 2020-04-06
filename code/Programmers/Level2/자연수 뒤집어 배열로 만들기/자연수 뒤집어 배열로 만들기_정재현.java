class Solution {
  public int[] solution(long n) {
      String tempStr = new String(n+"");
      char[] tempChar = tempStr.toCharArray();
      int[] answer = new int[tempChar.length];
      for(int i=0; i<tempChar.length; i++){
          answer[i]=Integer.parseInt(tempChar[tempChar.length-1-i]+"");
      }
      return answer;
  }
}