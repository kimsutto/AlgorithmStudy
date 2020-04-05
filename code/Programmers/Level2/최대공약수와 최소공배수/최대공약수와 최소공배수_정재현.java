class Solution {
    public int[] solution(int a, int b) {
        int[] answer = new int[2];
        int temp = 1;
        int multi = a*b;
        
        while(temp!=0)
        {
            temp=b%a;
            b=a;
            a=temp;
        }
        answer[0]=b;
        answer[1]=multi/b;
        
        return answer;
    }
}