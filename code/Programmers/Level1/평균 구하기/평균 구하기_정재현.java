class Solution {
  public double solution(int[] arr) {
      double answer = 0;
      double sum =0;

      if(arr.length>=1 && arr.length<=100){
          for(int j=0; j<arr.length; j++){
          sum+=arr[j];
          }
          answer=(double)(sum/arr.length);
      }
      return answer;
  }
}