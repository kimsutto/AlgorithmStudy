class Solution {
  public String solution(String s) {
    String answer ="";
    int leng = s.length();
    if(leng%2==1) {
        answer =  s.substring(leng/2,leng/2+1);
	    return answer;
    }else {
	    answer = s.substring(leng/2-1,leng/2+1);
	    return answer;    
    }
}
}