import java.util.*;
class Solution {
    public int solution(int[] d, int budget) {
        int counter = 0;
        int sum = 0;
        Arrays.sort(d);
        for(int i : d){
            sum += i;
            if(sum>budget)
                break;
            counter++;
        }
        return counter;
    }
}