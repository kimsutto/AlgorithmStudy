class Solution{
    public String solution(int a, int b){
    	String[] weeks={"THU","FRI","SAT","SUN","MON","TUE","WED"};
    	int[] days={31,29,31,30,31,30,31,31,30,31,30,31};
    	
    	for (int i=1;i<a;i++)
    		b+=days[i-1];
    	
    	return weeks[(b%7)];
    }
}